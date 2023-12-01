CXX = g++
CXXFLAGS = -std=c++14 -Werror -Wuninitialized
SRCDIR = src
BUILDDIR = build
TESTDIR = test-io
INPUTDIR = $(TESTDIR)/input-files
OUTPUTDIR = $(TESTDIR)/output-files
EXPECTEDDIR = $(TESTDIR)/expected-output-files

# All custom tests are visualized on https://csacademy.com/app/graph_editor/ and calculated on Matlab

# List of test numbers

# add or remove tests here
TESTS = 1 2

.PHONY: all clean

all: $(addprefix test, $(TESTS))

clean:
	rm -rf $(BUILDDIR)/* $(OUTPUTDIR)/*

define run_test
test$(1): $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILDDIR)/test_io $(SRCDIR)/main.cpp
	$(BUILDDIR)/test_io < $(INPUTDIR)/$(1).txt > $(OUTPUTDIR)/$(1).txt
	diff -w $(EXPECTEDDIR)/$(1).txt $(OUTPUTDIR)/$(1).txt
endef

$(foreach test,$(TESTS),$(eval $(call run_test,$(test))))
