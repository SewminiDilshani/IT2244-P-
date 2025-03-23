@echo off
:: Turns off command echoing to make the script output cleaner.

:: Display the title as 'Birthday calculater'
echo Birthday calculater

:: Prompt the user to enter their birth year
set /p birth_year=Enter your Birth Year:

:: Display current date
echo %date%

:: Extracts the current year from the system date
set current_year=%date:~10,4%

:: Calculates the age by subtracting the birth year from the current year
set /a age=%current_year%-%birth_year%

:: Display age
echo you are %age% years old.

:: Extract the current date and display it.
set current_date=%date:~7,2%
echo current date is %current_date%

:: Extract the current month and display it.
set current_month=%date:~4,2%
echo current month is %current_month%

:: Display the current year.
echo current year is %current_year%

:: Prompts the user to enter their birth day date
set /p birth_day=Enter your Birth Date:

:: Attempts to calculate the difference between the current day and birth day
set /a datediff=%current_date%-%birth_day%
echo Date difference is %datediff%

:: Prompts the user to enter their birth month
set /p birth_month=Enter your Birth Month:

:: Attempts to calculate the difference between the current month and birth month
set /a monthdiff=%current_month%-%birth_month%
echo Month difference is %monthdiff%

:: Pause the script execution, user can see the output before the window close
pause
