##
## EPITECH PROJECT, 2019
## CPE_dante_2018
## File description:
## Makefile
##

all:
	$(MAKE) --no-print-directory -C generator-files
	$(MAKE) --no-print-directory -C solver-files

clean:
	$(MAKE) --no-print-directory -C generator-files clean
	$(MAKE) --no-print-directory -C solver-files clean

fclean:
	$(MAKE) --no-print-directory -C generator-files fclean
	$(MAKE) --no-print-directory -C solver-files fclean

re:
	$(MAKE) --no-print-directory -C generator-files re
	$(MAKE) --no-print-directory -C solver-files re

