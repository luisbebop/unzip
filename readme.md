## unzip utility

Based on http://svn.ghostscript.com/ghostscript/trunk/gs/zlib/contrib/puff/puff.c and unzip.c and unzip.h
ANSI C and easily portable.

Build on Linux or Mac

```bash
$ gcc unzip.c -o unzip
$ ./unzip
process_local_file_header
process_local_file_header lrec.compressed_size=34
process_local_file_header lrec.compression_method=8
process_local_file_header lrec.uncompressed_size=43
process_local_file_header lrec.crc32=2914972667
process_local_file_header filename=params.dat
process_local_file_header lrec.filename_length=10
process_local_file_header lrec.extra_field_length=0
puff() succeeded uncompressing 43 bytes
process_local_file_header
process_local_file_header lrec.compressed_size=2219
process_local_file_header lrec.compression_method=8
process_local_file_header lrec.uncompressed_size=6872
process_local_file_header lrec.crc32=822808123
process_local_file_header filename=emv_acquirer_aids_04.dat
process_local_file_header lrec.filename_length=24
process_local_file_header lrec.extra_field_length=0
puff() succeeded uncompressing 6872 bytes
process_central_file_header
process_central_file_header
process_end_central_dir
UnzipFile ret=0
```

It will decompress test2.zip (2495 bytes) that contains params.dat (43 bytes) and  emv_acquirer_aids_04.dat (6872 bytes)
The file test.zip was generated on mac os zip default compress utility that don't add the zip correct headers
Both test2.zip and test3.zip was generated with WinRAR, zip mode, best compression. WinRAR generated the correct zip headers otherwise the parse it would be so much difficult.
