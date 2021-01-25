dirs := $(shell for i in *; do if [[ -d $$i && -f $$i/main.cc ]]; then echo $$i; fi; done)
objects := $(addsuffix /a.out, ${dirs})
cppflags := -std=c++20 -g

${objects} : $(addsuffix /main.cc, ${dirs})
	g++ ${cppflags} -o $@ $<

.PHONY : clean compiledb

compiledb :
	compiledb -n make  -B

clean :
	- rm -f */a.out
