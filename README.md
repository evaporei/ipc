# ipc

## Pipes

Two programs:

```bash
$ cc -o write write.c
$ cc -o read read.c
$ ./write | ./read
read: test
```

All in one:

```bash
$ cc -o all_in_one all_in_one.c
$ ./all_in_one
PARENT: reading from pipe
 CHILD: writing to the pipe
 CHILD: exiting
PARENT: read "test"
```

Count, same as `ls | wc -l`:

```bash
$ cc -o count count.c
$ ./count
12
```

## References:

- https://beej.us/guide/bgipc/html//index.html#pipes
