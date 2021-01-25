cppflags := -std=c++20 -g

dirs := $(shell for i in *; do if [[ -d $$i && -f $$i/main.cc ]]; then echo $$i; fi; done)
$(info dirs = ${dirs})

.PHONY : all clean compiledb

all : $(addsuffix /a.out, ${dirs})

$(addsuffix /a.out, ${dirs}) : $(addsuffix /main.cc, ${dirs})
	g++ ${cppflags} -o $@ $(subst a.out,main.cc,$@)

compiledb :
	compiledb -n make  -B

clean :
	- rm -f */a.out
