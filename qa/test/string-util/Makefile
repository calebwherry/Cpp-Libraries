#############################
##
##  File:
##      \file Makefile
##
##  Description:
##      \brief String Utilities tests makefile for C++ Libraries
##
##  Author:
##      \author J. Caleb Wherry
##
#############################

ROOT = $(abspath ../../..)
SRCS = $(wildcard *.cpp)
PROGS = $(SRCS:%.cpp=%)
INCLUDES += -I$(ROOT)/lib/StringUtil
LIBS += -L$(ROOT)/lib/StringUtil -lstringUtil

include $(abspath ../Makefile-test.common)
