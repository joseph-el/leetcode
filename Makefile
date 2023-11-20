NAME := leetcode_exec

CFILES   := $(addprefix c-language/, $(ARGS) )
CPPFILES := $(addprefix cpp-language/, $(ARGS) )

# add fuction to be run: make cpp ARGS=TwoSum.cpp
cpp :
	@echo "leetcode_exec [✅]"
	@c++ -std=c++2a $(CPPFILES)  core/leet_main.cpp  -I includes/  -o $(NAME)
c :
	@echo "leetcode_exec [✅]"
	@gcc  $(CFILES) core/leet_main.c -I includes/ -o $(NAME)

# add swift-file path after swift target : make swift ARG=print-tree.swift
swift :
	@echo "swift [🏊🏻‍♀️]"
	swift $(ARGS)

clean :
	@echo "clean [🥶]"
	@rm -drf $(NAME) *.out

.PHONY : clean c cpp swift