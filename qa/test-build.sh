#! /bin/bash
#############################
##
##  File:
##      \file test-build.sh
##
##  Description:
##      \brief Test Build Script
##
##  Author:
##      \author J. Caleb Wherry
##
#############################

# Start time:
START_TIME=$(date +%s)

# Project name:
PROJ="Cpp-Libraries"
FULL_PROJ="calebwherry/${PROJ}"

# Get time stamp:
TIMESTAMP="`date +\"%d-%m-%Y_%T\"`"

# Build directory name:
BUILD_DIR="build_${TIMESTAMP}"

# Logfile name:
LOGFILE="output_${TIMESTAMP}.log"

# Exit status of commands:
STATUS=0

# Create build directory:
echo
echo -n "Creating build directory... "
(
mkdir -p "${BUILD_DIR}"
) >> ${LOGFILE} 2>&1
STATUS=$?

if [ ${STATUS} -ne 0 ]
then
    echo "** ERROR: Could not create build directory, please check ${LOGFILE}. **"
    exit 1
else
    echo "done."
fi

# Clone the git repo for the nightly build:
echo -n "Cloning git project ${FULL_PROJ} into ${BUILD_DIR}... "
(
git clone git@github.com:${FULL_PROJ}.git "${BUILD_DIR}"
) >> ${LOGFILE} 2>&1
STATUS=$?

if [ ${STATUS} -ne 0 ]
then
    echo "** ERROR: Could not clone project, please check ${LOGFILE}. **"
    exit 1
else
    echo "done."
fi

# CD into new build:
cd "${BUILD_DIR}"

# Run make:
echo -n "Running make... "
(
make
) >> ${LOGFILE} 2>&1
STATUS=$?

if [ ${STATUS} -ne 0 ]
then
    echo "** ERROR: Make problem encountered, please check ${LOGFILE}. **"
    exit 1
else
    echo "done."
fi

# Run make test:
echo -n "Running make test... "
(
make test
) >> ${LOGFILE} 2>&1
STATUS=$?

if [ ${STATUS} -ne 0 ]
then
    echo "** ERROR: Make test problem encountered, please check ${LOGFILE}. **"
    exit 1
else
    echo "done."
fi

# Run project tests:
echo -n "Running make run-test... "
(
make run-test
) >> ${LOGFILE} 2>&1
STATUS=$?

if [ ${STATUS} -ne 0 ]
then
    echo "** ERROR: make run-test problem encountered, please check ${LOGFILE} for test failures. **"
    exit 1
else
    echo "done."
fi

# All tests completed:
echo "All test completed successfully!"

# Do some cleanup:
cd ..
rm -rf "${BUILD_DIR}" ${LOGFILE}

# Stop time:
STOP_TIME=$(date +%s)

# Elapsed time:
echo
echo "Test Build Execution Time: $(expr ${STOP_TIME} - ${START_TIME}) seconds."
echo

# Exit cleanly:
exit 0
