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

## FIFOs

You'll need two terminals.

```bash
$ cc -o tick tick.c
$ ./tick
waiting for writers...
got a writer
tick: read 6 bytes: "hallo
"
tick: read 0 bytes: ""
```

Second:

```bash
$ cc -o speak speak.c
$ ./speak
waiting for readers...
got a reader--type some stuff
hallo
speak: wrote 6 bytes
^C⏎
```

## References:

- https://beej.us/guide/bgipc/html//index.html#pipes
- https://beej.us/guide/bgipc/html//index.html#fifos
