LINKED_LIBS = libKombilo \
              libIOInterface \
              libTest


BUILD_TIME_TESTS=kombilo

USE_BOOST=YES
USE_SQLITE=YES
MODE=CPP

# Boost makes to much noise...
FATAL_WARNINGS=NO

.TEST_SETUP:
	rm 	db/*

include ../makefile.include
