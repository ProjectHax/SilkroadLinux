#!/usr/bin/env python3
import re
import mmap

pattern = re.compile(br'\x83\xF8\xFF\x75\x19\x68....\x55\xFF\x15....\x3B\xC3\xA3....\x0F\x84....\x3B\xEB\x74\x07\x55\xFF\x15....\x56\xFF\x15....\x8B\x4C\x24\x44\x5F\x5E\x5D\x5B\x33\xCC\xB8\x01\x00\x00\x00\xE8....\x83\xC4\x3C\xC3\xCC')

def patch(path):

	try:

		f = open(path, 'r+b')
		mm = mmap.mmap(f.fileno(), 0)

		count = 0

		for match in pattern.finditer(mm):

			offset = match.start() + 3

			print('\tpatch offset %d' % offset)

			mm.seek(offset)
			mm.write_byte(0xEB)
			mm.seek(0)

			count += 1

		mm.close()
		f.close()

		if count == 0:
			print('\tno patches were made -- already patched or outdated regular expression')
		elif count == 1:
			print('\t1 patch was applied')
		else:
			print('\t%d patches were applied' % count)

	except Exception as e:

		print(e)

def main():

	print('Patching sro_client.exe')
	patch('sro_client.exe')

	print('Patching silkroad.exe')
	patch('silkroad.exe')

if __name__ == '__main__':
	main()