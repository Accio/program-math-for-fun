B=bin
S=src
O=obj

install:obj
	cp -p ${O}/sim-monty-hall ${B}/

obj:${O}/sim-monty-hall

${O}/sim-monty-hall:${S}/sim-monty-hall.c
	$(CC) ${S}/sim-monty-hall.c -o ${O}/sim-monty-hall


