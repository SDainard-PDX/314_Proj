#!/bin/bash
#bash script to test Chocan

echo
echo Chocan All Tests

#Chocan all tests
#./functional_tests

echo
echo Chocan Smoke Test
#smoke tests
./functional_smoke_tests

echo
echo Chocan verification tests
#verification tests
./functional_verify_tests

echo