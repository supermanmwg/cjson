all:read write
read: read.c cjson.c
	gcc read.c cjson.c  -o read -g -lm
write: write.c cjson.c
	gcc write.c cjson.c -o  write -g -lm

clean:
	rm read write

