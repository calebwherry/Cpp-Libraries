#############################
##
##  File:
##      \file Makefile
##
##  Description:
##      \brief Searching tests makefile for C++ Libraries
##
##  Author:
##      \author J. Caleb Wherry
##
#############################

ROOT = $(abspath ../../..)
SRCS = $(wildcard *.cpp)
PROGS = $(SRCS:%.cpp=%)
INCLUDES += -I$(ROOT)/lib/Searching
LIBS += -L$(ROOT)/lib/Searching -lsearching

include $(abspath ../Makefile-test.common)
