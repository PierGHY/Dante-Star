##
## EPITECH PROJECT, 2019
## CPE_dante_2018
## File description:
## Makefile
##

all:
	@$(MAKE) --no-print-directory -C generator
	@$(MAKE) --no-print-directory -C solver

clean:
	@$(MAKE) --no-print-directory -C generator clean
	@$(MAKE) --no-print-directory -C solver clean

fclean:
	@$(MAKE) --no-print-directory -C generator fclean
	@$(MAKE) --no-print-directory -C solver fclean

re:
	@$(MAKE) --no-print-directory -C generator re
	@$(MAKE) --no-print-directory -C solver re

