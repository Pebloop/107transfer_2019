.PHONY = debug retest re

SRC =   src/transfert.c

MAIN =  main.c

OBJ =   $(SRC:.c=.o)

MAIN_OBJ =  $(MAIN:.c=.o)


CFLAGS = -Iinclude/ \
-Llib/fae/ -lfae

NAME =  107transfert

TEST =  107transfert.t

DEBUG = 107transfert.d

all: $(NAME)

make_lib:
	@echo ' ___  ___  ___                         _  _        _  _  _         ___  ___  ___'
	@echo '|___||___||___|  ___  ___  _ _ _  ___ <_>| | ___  | |<_>| |_  ___ |___||___||___|'
	@echo ' ___  ___  ___  / |  / . \|     || . \| || |/ ._> | || || . \<_-<  ___  ___  ___'
	@echo '|___||___||___| \_|_.\___/|_|_|_||  _/|_||_|\___. |_||_||___//__/ |___||___||___|'
	@echo '                                 |_|'
	make -C lib/fae

$(NAME): make_lib $(OBJ) $(MAIN_OBJ)
	@echo ' ___  ___  ___                         _  _                                              ___  ___  ___'
	@echo '|___||___||___|  ___  ___  _ _ _  ___ <_>| | ___   ___  _ _  ___  ___  _ _  ___  _ _ _  |___||___||___|'
	@echo ' ___  ___  ___  / |  / . \|     || . \| || |/ ._> | . \|  _>/ . \/ . ||  _><_> ||     |  ___  ___  ___'
	@echo '|___||___||___| \_|_.\___/|_|_|_||  _/|_||_|\___. |  _/|_|  \___/\_. ||_|  <___||_|_|_| |___||___||___|'
	@echo '                                 |_|              |_|            <___|'
	gcc -o $(NAME) $(MAIN_OBJ) $(OBJ) $(CFLAGS)

debug: make_lib $(OBJ) $(MAIN_OBJ)
	gcc -g3 -o $(DEBUG) $(MAIN_OBJ) $(OBJ) $(CFLAGS)

tests_run: make_lib
	gcc -o $(TEST) $(OBJ) $(CFLAGS)
	./$(TEST)

retest: fclean tests_run

clean:
	@echo ' ___  ___  ___        _                  ___  ___  ___'
	@echo '|___||___||___|  ___ | | ___  ___  _ _  |___||___||___|'
	@echo ' ___  ___  ___  / |  | |/ ._><_> ||   |  ___  ___  ___'
	@echo '|___||___||___| \_|_.|_|\___.<___||_|_| |___||___||___|'
	make clean -C lib/fae/
	rm -f $(OBJ) $(MAIN_OBJ)

fclean: clean
	@echo ' ___  ___  ___   ___      _                  ___  ___  ___'
	@echo '|___||___||___| | |  ___ | | ___  ___  _ _  |___||___||___|'
	@echo ' ___  ___  ___  | |-/ |  | |/ ._><_> ||   |  ___  ___  ___'
	@echo '|___||___||___| |_| \_|_.|_|\___.<___||_|_| |___||___||___|'
	make fclean -C lib/fae/
	rm -f $(TEST) $(NAME)

re: fclean all
