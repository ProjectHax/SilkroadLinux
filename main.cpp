#include <iostream>
#include <fstream>
#include <string>

#ifndef NO_BOOST
	#include <boost/regex.hpp>
#else
	#error "Boost.Regex is required for SilkroadLinux to compile successfully"
	#error "https://github.com/ProjectHax/SilkroadLinux"
#endif

void PatchEXE(const std::string & path)
{
	std::ifstream ifs(path.c_str(), std::ios::in | std::ios::binary);
	if(ifs.is_open())
	{
		std::string data((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
		ifs.close();

		const boost::regex e("\\x83\\xF8\\xFF(?<data>\\x75\\x19)\\x68....\\x55\\xFF\\x15....\\x3B\\xC3\\xA3....\\x0F\\x84....\\x3B\\xEB\\x74\\x07\\x55\\xFF\\x15....\\x56\\xFF\\x15....\\x8B\\x4C\\x24\\x44\\x5F\\x5E\\x5D\\x5B\\x33\\xCC\\xB8\\x01\\x00\\x00\\x00\\xE8....\\x83\\xC4\\x3C\\xC3\\xCC");

		boost::match_results<std::string::const_iterator> what;
		boost::match_flag_type flags = boost::match_default;

		std::string::const_iterator start = data.begin();
		std::string::const_iterator end = data.end();

		std::fstream fs(path.c_str(), std::fstream::binary | std::fstream::out | std::fstream::in);
		if(!fs.is_open())
		{
			std::cout << "\t" << "could not open " << path << " for writing" << std::endl;
			return;
		}

		const char patch = 0xEB;
		int count = 0;

		try
		{
			while(boost::regex_search(start, end, what, e, flags))
			{
				size_t offset = what.position("data");

				std::cout << "\t" << "patch offset: " << offset << std::endl;

				fs.seekg(offset, std::ios::beg);
				fs.write(&patch, 1);

				start = what[0].second;
				flags |= boost::match_prev_avail;
				flags |= boost::match_not_bob;

				count++;
			}
		}
		catch(std::exception & e)
		{
			std::cout << "\t" << e.what() << std::endl;
		}

		fs.close();

		if(count == 0)
		{
			std::cout << "\t" << "no patches were made -- already patched or outdated regular expression" << std::endl;
		}
		else
		{
			std::cout << "\t" << count << " patches were applied" << std::endl;
		}
	}
	else
	{
		std::cout << "\t" << path << " could not be opened" << std::endl;
	}
}

int main(int argc, char* argv[])
{
	std::cout << "ProjectHax Silkroad For Linux Patcher" << std::endl << std::endl;

	std::cout << "Patching sro_client.exe" << std::endl;
	PatchEXE("sro_client.exe");

	std::cout << std::endl << "Patching silkroad.exe" << std::endl;
	PatchEXE("silkroad.exe");

	return 0;
}
