LINKED_LIBS = libKombilo \
              libSimpleAPI\
              libIOInterface \
			  libUtils\
              libTest


BUILD_TIME_TESTS=kombilo

USE_BOOST=YES
USE_SQLITE=YES
MODE=CPP

# Boost makes to much noise...
FATAL_WARNINGS=NO

.TEST_SETUP:
	mkdir -p db
	rm 	-f db/*

include ../makefile.include
