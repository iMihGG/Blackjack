#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <time.h>

typedef struct Cards {
    char suite;
    int value;
} Cards;

int credits = 1000;

void game(Cards *c);

void diamond(WINDOW *win, int a) {
    wbkgd(win, COLOR_PAIR(1));
    if(a < 11) {
        mvwprintw(win, 1, 2, "%d", a);
    } else {
        if(a == 11) {
            a = 65;
            mvwprintw(win, 1, 2, "%c", a);
        } else {
            if(a == 12) {
                a = 74;
                mvwprintw(win, 1, 2, "%c", a);
            } else {
                if(a == 13) {
                    a = 81;
                    mvwprintw(win, 1, 2, "%c", a);
                } else {
                    a = 75;
                    mvwprintw(win, 1, 2, "%c", a);
                }
            }
        }
    }
    mvwprintw(win, 2, 2, "*");
    mvwprintw(win, 3, 1, "*");
    mvwprintw(win, 3, 3, "*");
    mvwprintw(win, 4, 2, "*");
    if(a < 11) {
        mvwprintw(win, 12, 14, "%d", a);
    } else {
        mvwprintw(win, 12, 14, "%c", a);
    }
    mvwprintw(win, 9, 14, "*");
    mvwprintw(win, 10, 15, "*");
    mvwprintw(win, 10, 13, "*");
    mvwprintw(win, 11, 14, "*");
    wrefresh(win);
}

void heart(WINDOW *win, int a) {
    wbkgd(win, COLOR_PAIR(1));
    if(a < 11) {
        mvwprintw(win, 1, 2, "%d", a);
    } else {
        if(a == 11) {
            a = 65;
            mvwprintw(win, 1, 2, "%c", a);
        } else {
            if(a == 12) {
                a = 74;
                mvwprintw(win, 1, 2, "%c", a);
            } else {
                if(a == 13) {
                    a = 81;
                    mvwprintw(win, 1, 2, "%c", a);
                } else {
                    a = 75;
                    mvwprintw(win, 1, 2, "%c", a);
                }
            }
        }
    }
    mvwprintw(win, 2, 1, "*");
    mvwprintw(win, 2, 3, "*");
    mvwprintw(win, 3, 1, "*");
    mvwprintw(win, 3, 2, "*");
    mvwprintw(win, 3, 3, "*");
    mvwprintw(win, 4, 2, "*");
    if(a < 11) {
        mvwprintw(win, 12, 14, "%d", a);
    } else {
        mvwprintw(win, 12, 14, "%c", a);
    }
    mvwprintw(win, 9, 13, "*");
    mvwprintw(win, 9, 15, "*");
    mvwprintw(win, 10, 13, "*");
    mvwprintw(win, 10, 14, "*");
    mvwprintw(win, 10, 15, "*");
    mvwprintw(win, 11, 14, "*");
    wrefresh(win);
}

void club(WINDOW *win, int a) {
    wbkgd(win, COLOR_PAIR(2));
    if(a < 11) {
        mvwprintw(win, 1, 2, "%d", a);
    } else {
        if(a == 11) {
            a = 65;
            mvwprintw(win, 1, 2, "%c", a);
        } else {
            if(a == 12) {
                a = 74;
                mvwprintw(win, 1, 2, "%c", a);
            } else {
                if(a == 13) {
                    a = 81;
                    mvwprintw(win, 1, 2, "%c", a);
                } else {
                    a = 75;
                    mvwprintw(win, 1, 2, "%c", a);
                }
            }
        }
    }
    mvwprintw(win, 2, 2, "^");
    mvwprintw(win, 3, 1, "(");
    mvwprintw(win, 3, 3, ")");
    mvwprintw(win, 4, 2, "&");
    if(a < 11) {
        mvwprintw(win, 12, 14, "%d", a);
    } else {
        mvwprintw(win, 12, 14, "%c", a);
    }
    mvwprintw(win, 9, 14, "^");
    mvwprintw(win, 10, 15, ")");
    mvwprintw(win, 10, 13, "(");
    mvwprintw(win, 11, 14, "&");
    wrefresh(win);
}

void spade(WINDOW *win, int a) {
    wbkgd(win, COLOR_PAIR(2));
    if(a < 11) {
        mvwprintw(win, 1, 2, "%d", a);
    } else {
        if(a == 11) {
            a = 65;
            mvwprintw(win, 1, 2, "%c", a);
        } else {
            if(a == 12) {
                a = 74;
                mvwprintw(win, 1, 2, "%c", a);
            } else {
                if(a == 13) {
                    a = 81;
                    mvwprintw(win, 1, 2, "%c", a);
                } else {
                    a = 75;
                    mvwprintw(win, 1, 2, "%c", a);
                }
            }
        }
    }
    mvwprintw(win, 2, 2, "*");
    mvwprintw(win, 3, 1, "*");
    mvwprintw(win, 3, 2, "*");
    mvwprintw(win, 3, 3, "*");
    mvwprintw(win, 4, 1, "*");
    mvwprintw(win, 4, 2, "&");
    mvwprintw(win, 4, 3, "*");
    if(a < 11) {
        mvwprintw(win, 12, 14, "%d", a);
    } else {
        mvwprintw(win, 12, 14, "%c", a);
    }
    mvwprintw(win, 9, 14, "*");
    mvwprintw(win, 10, 13, "*");
    mvwprintw(win, 10, 14, "*");
    mvwprintw(win, 10, 15, "*");
    mvwprintw(win, 11, 13, "*");
    mvwprintw(win, 11, 14, "&");
    mvwprintw(win, 11, 15, "*");
    wrefresh(win);
}
/*the 4 functions defined above are used to draw the suits of the cards*/

void shuffle(Cards *c, int n) {
    srand(time(0));
    int i, j;
    Cards aux;
    for(i = 0; i < 52; i++) {
        int j = rand() % n;
        aux.suite = c[i].suite;
        c[i].suite = c[j].suite;
        c[j].suite = aux.suite;
        aux.value = c[i].value;
        c[i].value = c[j].value;
        c[j].value = aux.value;
    }
}
/*shuffles the deck of cards with a different seed for every execution*/

void deck() {
    int i, j, k;
    for(i = 0 ; i < 20; i++) {
        WINDOW *win = newwin(14, 17, 28, (23 + i) / 3);
        wbkgd(win, COLOR_PAIR(4));
        box(win, 0 ,0);
        for(j = 1; j <= 12; j++) {
            for(k = 2; k <= 15; k++) {
                if(k % 2 == 0) {
                    mvwprintw(win, j, k, "<");
                } else {
                    mvwprintw(win, j, k, ">");
                }
            }
        }
        refresh();
        wrefresh(win);
    }
}
/*prints a deck of cards in the down left corner*/

void menu(int a, Cards *c) {
    initscr();
    WINDOW *menuwin = newwin(6, 12, 15 ,60);
    box(menuwin, 0, 0);
    if(a > 0) {
        wbkgd(menuwin, COLOR_PAIR(7));
        mvwprintw(menuwin, 4, 4, "WIN!");
    } else {
        if(a < 0) {
            mvwprintw(menuwin, 4, 1, "GAME OVER!");
            wbkgd(menuwin, COLOR_PAIR(5));
        } else {
            mvwprintw(menuwin, 4, 4, "DRAW!");
            wbkgd(menuwin, COLOR_PAIR(6));
        }
    }
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);
    char options[2][100] = {"New game", "Exit"};
    int alegere;
    int highlight = 0;
    while(1) {
        int i;
        for(i = 0; i < 2; i++) {
            if(i == highlight) {
                wattron(menuwin, A_REVERSE);
            }
            mvwprintw(menuwin, i + 1, 1, options[i]);
            wattroff(menuwin, A_REVERSE);
        }
        alegere = wgetch(menuwin);
        switch(alegere) {
            case KEY_UP:
                highlight--;
                if(highlight == -1) {
                    highlight = 1;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == 2) {
                    highlight = 0;
                }
                break;
            default:
                break;
        }
        if(alegere == 10) {
            break;
        }
    }
    if(strcmp(options[highlight], "New game") == 0) {
        clear();
        game(c);
    } else {
        endwin();
        exit(0);
    }
}
/*the menu function which displays everytime a game ends and provides
two options: start a new game or exit*/

void addDeck(Cards *c) {
    int i;
    for(i = 0 ; i < 13; i++) {
        c[i].value = i + 2;
        c[i].suite = 'c';
    }
    for(i = 13 ; i < 26; i++) {
        c[i].value = (i - 13) + 2;
        c[i].suite = 'd';
    }
    for(i = 26 ; i < 39; i++) {
        c[i].value = (i - 26) + 2;
        c[i].suite = 'h';
    }
    for(i = 39 ; i < 52; i++) {
        c[i].value = (i - 39) + 2;
        c[i].suite = 's';
    }
}
/*fills the array of Cards structure*/

void player_bet(int *bet, int credits) {
    *bet = 0;
    initscr();
    WINDOW *errwin = newwin(3, 40, 1 ,1);
    WINDOW *menuwin = newwin(8, 14, 8 ,5);
    wbkgd(menuwin, COLOR_PAIR(8));
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);
    char options[6][100] = {"50", "100", "200", "MAX", "DONE"};
    /*the player is provided 4 options for bets, as well as a button
    which he uses when his bet is ready*/
    int alegere;
    int highlight = 0;
    while(1) {
        int i;
        for(i = 0; i < 5; i++) {
            if(i == highlight) {
                wattron(menuwin, A_REVERSE);
            }
            mvwprintw(menuwin, i + 1, 1, options[i]);
            wattroff(menuwin, A_REVERSE);
        }
        alegere = wgetch(menuwin);
        wclear(errwin);
        wbkgd(errwin, COLOR_PAIR(3));
        wrefresh(errwin);
        refresh();
        /*in case an error occured, the window designated to show it is
        cleared*/
        switch(alegere) {
            case KEY_UP:
                highlight--;
                if(highlight == -1) {
                    highlight = 4;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == 5) {
                    highlight = 0;
                }
                break;
            default:
                break;
        }
        if(alegere == 10) {
            if(strcmp(options[highlight], "50") == 0) {
                *bet = *bet + 50;
            } else {
                if(strcmp(options[highlight], "100") == 0) {
                    *bet = *bet + 100;
                } else {
                    if(strcmp(options[highlight], "200") == 0) {
                        *bet = *bet + 200;
                    } else {
                        if(strcmp(options[highlight], "MAX") == 0) {
                            *bet = credits;
                        } else {
                            if(strcmp(options[highlight], "DONE") == 0
                            && *bet){
                                break;
                            } else {
                                wbkgd(errwin, COLOR_PAIR(5));
                                mvwprintw(errwin, 1, 1,
                                "BET SOME OF YOUR GAINED CREDITS!");
                                wrefresh(errwin);
                                refresh();
                                /*an error message displays if there is no
                                credit bet*/
                            }
                        }
                    }
                }
            }
            if(*bet > credits) {
                wbkgd(errwin, COLOR_PAIR(5));
                mvwprintw(errwin, 1, 1,"INSSUFICIENT CREDITS! BET LESS!");
                wrefresh(errwin);
                refresh();
                /*an error message prints if the bet is greater than the
                credits*/
                *bet = 0;
            }
            mvwprintw(menuwin, 6, 1, "BET IS: %d", *bet);
        }
    }
    endwin();
    clear();
}

void hit_or_stay(int *decision) {
    initscr();
    WINDOW *menuwin = newwin(6, 12, 14 ,5);
    wbkgd(menuwin, COLOR_PAIR(8));
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);
    char options[2][100] = {"Hit", "Stay"};
    int alegere;
    int highlight = 0;
    while(1) {
        int i;
        for(i = 0; i < 2; i++) {
            if(i == highlight) {
                wattron(menuwin, A_REVERSE);
            }
            mvwprintw(menuwin, i + 1, 1, options[i]);
            wattroff(menuwin, A_REVERSE);
        }
        alegere = wgetch(menuwin);
        switch(alegere) {
            case KEY_UP:
                highlight--;
                if(highlight == -1) {
                    highlight = 1;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == 2) {
                    highlight = 0;
                }
            default:
                break;
        }
        if(alegere == 10) {
            break;
        }
    }
    if(strcmp(options[highlight], "Hit") == 0) {
        *decision = 1;
    } else {
        *decision = 0;
        endwin();
        wrefresh(menuwin);
        delwin(menuwin);
    }
}
/*the window for hit and stay*/

void game(Cards *c) {
    WINDOW *a[11][11];
    mvprintw(0, 60, "BLACKJACK");
    refresh();
    int bet, decision;
    deck();
    shuffle(c, 52);
    player_bet(&bet, credits);
    deck();
    int dealer = c[2].value + c[3].value;
    int player = c[0].value + c[1].value;
    mvprintw(1, 10, "Credits available: %d", credits - bet);
    mvprintw(2, 10, "Bet: %d", bet);
    mvprintw(10, 10, "Player's cards: %d", player);
    mvprintw(11, 10, "Dealer's cards: %d", dealer);
    int start_y = 6, start_x = 35;
    int i, j, x, pace = 0, dace = 0;
    for(i = 0; i < 2; i++) {
        if(i % 2 == 0) {
            x = 0;
        } else {
            x = 1;
        }
        for(j = 0; j < 2; j++) {
            a[i][j] = newwin(14, 17, start_y + 14 * i, start_x + 17 * j);
            box(a[i][j], 0, 0);
            refresh();
            wrefresh(a[i][j]);
            if(c[i + j + x].suite == 'c') {
                club(a[i][j], c[i + j + x].value);
            } else {
                if(c[i + j + x].suite == 'd') {
                    diamond(a[i][j], c[i + j + x].value);
                } else {
                    if(c[i + j + x].suite == 'h') {
                        heart(a[i][j], c[i + j + x].value);
                    } else {
                        spade(a[i][j], c[i + j + x].value);
                    }
                }
            }
            if(c[i + j + x].value == 11) {
                if(x == 0) {
                    pace++;
                } else {
                    dace++;
                }
            }
        }
    }
    /*two random cards are each given to the player and dealer*/
    if(player > 21 && pace) {
        player = player - 10;
        pace--;
    }
    if(dealer > 21 && dace) {
        dealer = dealer - 10;
        dace--;
    }
    /*checking any of the two has an ace which should switch its value
    from 11 to 1*/
    if(player > 21) {
        credits = credits - bet;
        if(credits == 0) {
            credits = 1000;
        }
        menu(-1, c);
    } else {
        if(player == 21 && dealer == 21) {
            menu(0, c);
            credits = credits + bet / 2;
        } else {
            if(player == 21) {
                credits = credits + bet;
                menu(1, c);
            } else {
                if(dealer == 21) {
                    credits = credits - bet;
                    if(credits == 0) {
                        credits = 1000;
                    }
                    menu(-1, c);
                } else {
                    if(dealer > 21) {
                        credits = credits + bet;
                        menu(1, c);
                    }
                }
            }
        }
    }
    x = 1;
    while(1) {
        mvprintw(10, 10, "Player's cards: %d", player);
        mvprintw(11, 10, "Dealer's cards: %d", dealer);
        hit_or_stay(&decision);
        /*the decision of hit or stay is being processed*/
        if(decision) {
            a[0][j] = newwin(14, 17, start_y, start_x + 17 * j);
            box(a[0][j], 0, 0);
            refresh();
            wrefresh(a[0][j]);
            if(c[j].suite == 'c') {
                club(a[0][j], c[j].value);
            } else {
                if(c[j].suite == 'd') {
                    diamond(a[0][j], c[j].value);
                } else {
                    if(c[j].suite == 'h') {
                        heart(a[0][j], c[j].value);
                    } else {
                        spade(a[0][j], c[j].value);
                    }
                }
            }
            player = player + c[j].value;
            if(c[j].value == 11) {
                pace++;
            }
            if(player > 21 && pace) {
                player = player - 10;
                pace--;
            }
            j++;
        } else {
            mvprintw(10, 10, "Player's cards: %d", player);
            break;
        }
        if(player > 21) {
            mvprintw(10, 10, "Player's cards: %d", player);
            credits = credits - bet;
            if(credits == 0) {
                credits = 1000;
            }
            menu(-1, c);
        } else {
            if(player == 21) {
                credits = credits + bet;
                mvprintw(10, 10, "Player's cards: %d", player);
                break;
            }
        }
    }
    int obs = 1;
    int k, y = 2;
    for(k = 0; obs; k++) {
        if(c[j].value + dealer <= 21) {
            a[1][k] = newwin(14, 17, start_y + 14, start_x + 17 * y);
            box(a[1][k], 0, 0);
            refresh();
            wrefresh(a[1][k]);
            if(c[j].suite == 'c') {
                club(a[1][k], c[j].value);
            } else {
                if(c[j].suite == 'd') {
                    diamond(a[1][k], c[j].value);
                } else {
                    if(c[j].suite == 'h') {
                        heart(a[1][k], c[j].value);
                    } else {
                        spade(a[1][k], c[j].value);
                    }
                }
            }
            dealer = dealer + c[j].value;
            j++;
            y++;
            mvprintw(11, 10, "Dealer's cards: %d", dealer);
        } else {
            if(dace) {
                int z = j;
                int copy = dealer - 10;
                while(copy + c[z].value <= 21) {
                    copy = copy + c[z].value;
                    z++;
                }
                if(copy > dealer) { 
                    dealer = dealer - 10;
                    dace--;
                    a[1][k] = newwin(14, 17, start_y + 14, start_x + 17 * y);
                    box(a[1][k], 0, 0);
                    refresh();
                    wrefresh(a[1][k]);
                    if(c[j].suite == 'c') {
                        club(a[1][k], c[j].value);
                    } else {
                        if(c[j].suite == 'd') {
                            diamond(a[1][k], c[j].value);
                        } else {
                            if(c[j].suite == 'h') {
                            heart(a[1][k], c[j].value);
                            } else {
                                spade(a[1][k], c[j].value);
                            }
                        }
                    }
                    dealer = dealer + c[j].value;
                    j++;
                    y++;
                    mvprintw(11, 10, "Dealer's cards: %d", dealer);
                }
            } else {
                break;
            }
            mvprintw(11, 10, "Dealer's cards: %d", dealer);
        }
        if(dealer == 21) {
            mvprintw(11, 10, "Dealer's cards: %d", dealer);
            break;
        }
    }
    /*the dealer acts as an bot which knows what cards are next in the deck
    and only takes them if their sum will not be greater than 21*/
    int diff = player - dealer;
    if(diff > 0) {
        credits = credits + bet;
    } else {
        if(diff < 0) {
            credits = credits - bet;
            if(credits == 0) {
                credits = 1000;
            } else {
                credits = credits + bet / 2;
            }
        }
    }
    menu(diff, c);
}

int main() {
    initscr();
    noecho();
    start_color();
    init_pair(1, COLOR_RED, COLOR_WHITE);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3, COLOR_WHITE, COLOR_GREEN);
    init_pair(4, COLOR_BLUE, COLOR_WHITE);
    init_pair(5, COLOR_WHITE, COLOR_RED);
    init_pair(6, COLOR_WHITE, COLOR_YELLOW);
    init_pair(7, COLOR_WHITE, COLOR_BLUE);
    init_pair(8, COLOR_WHITE, COLOR_MAGENTA);
    Cards *c = (Cards*)malloc(53 * sizeof(Cards));
    addDeck(c);
    bkgd(COLOR_PAIR(3));
    game(c);
    getch();
    endwin();

    return 0;                         
        
}