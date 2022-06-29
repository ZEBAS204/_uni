@echo off

rem I'm lazy and use Prolog portable
rem So let's set the environment paths

set prodir=D:\Users\SEBAS\Downloads\swipl-8.4.3-1.x64\bin\
set path=%PATH%;%prodir%

rem Figure out versions for Git, Node.Js, and NPM. This first one breaks apart the Git version to make it look nicer.
for /f "tokens=3" %%n in ('swipl --version') do set prover=%%n

rem Print Prolog version to check if succeded
echo Prolog Version = v%prover%

rem Use $ swipl [commands+]
