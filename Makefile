
BOT = ./my_filler_bot/dgonor.filler

.PHONY: all, clean, fclean, re;

all: $(BOT)

$(BOT):
		@make -C my_filler_bot

clean:
		@make -C my_filler_bot clean

fclean: clean
		@make -C my_filler_bot fclean

re: fclean all
