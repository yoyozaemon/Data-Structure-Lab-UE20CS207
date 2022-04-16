#include <stdio.h>
#include <stdlib.h>
//structure of matchs
struct matchs
{
char *match_name;
int score;
char yes_no;
struct matchs *next;
};
//structure of players
struct players
{
char *player_name;
char *team_name;
struct matchs *match;
struct players *next;
};
struct players *head = NULL;
//add players from end
void add_player(char *name, char *team)
{
struct players *temp;
struct players *temp1;
temp = (struct players *)malloc(sizeof(struct players));
temp->player_name = name;
temp->team_name = team;
temp->match = NULL;
temp->next = NULL;
if (head == NULL)
{
head = temp;
}
else
{
temp1 = head;
while (temp1->next != NULL)
{
temp1 = temp1->next;
  }
temp1->next = temp;
}
}
//add matchs to players at top of match list
void add_matchs(char *name, int score, int pos, char yes_no)
{
int i = 1;
struct matchs *temp;
struct players *temp1;
if (head != NULL)
{
temp1 = head;
while (pos != i)
{
i++;
temp1 = temp1->next;
}
if (pos != i)
{
printf("There is no player at position %d\n", pos);
return;
}
temp = (struct matchs *)malloc(sizeof(struct matchs));
temp->match_name = name;
temp->yes_no = yes_no;
if (yes_no == 'y')
temp->score = score;
else
temp->score = 0;
if (temp1->match == NULL)
{
temp->next = NULL;
temp1->match = temp;
}
else
{
temp->next = temp1->match;
temp1->match = temp;
}
}
else
{
printf("There are no player\n");
}
return;
}
//display
void display()
{
  struct players *temp = head;
struct matchs *temp1;
int i, j = 1;
while (temp != NULL)
{
i = 1;
printf("%d\t", j++);
printf("%s\t", temp->player_name);
printf("%s\n", temp->team_name);
temp1 = temp->match;
while (temp1 != NULL)
{
printf("\t%d\t", i++);
printf("%s\t", temp1->match_name);
printf("%d\t", temp1->score);
if (temp1->yes_no == 'y')
printf("Played\n");
else
printf("Not Played\n");
temp1 = temp1->next;
}
temp = temp->next;
}
}
//maximum runs scored in match
void max_runs(char *name)
{
struct players *temp = head;
struct matchs *temp1;
char *player_name;
int score = 0;
if (head != NULL)
{
while (temp != NULL)
{
if (temp->match != NULL)
{
temp1 = temp->match;
while (temp1 != NULL)
{
if (temp1->match_name == name)
{
if (score < temp1->score)
{
player_name = temp->player_name;
score = temp1->score;
}
}
temp1 = temp1->next;
}
  }
temp = temp->next;
}
if (score != 0)
{
printf("\nMax Scored in %s is:\n", name);
printf("%s\t%d\n", player_name, score);
}
else
{
printf("There is no max score\n");
}
}
else
{
printf("There are no player\n");
}
return;
}
//total no of matchs played by all players
void total_matchs()
{
struct players *temp = head;
struct matchs *temp1;
int i = 1, j;
if (head != NULL)
{
printf("\n#\tName\tNo of matchs\n");
while (temp != NULL)
{
if (temp->match != NULL)
{
temp1 = temp->match;
j = 0;
while (temp1 != NULL)
{
if (temp1->yes_no == 'y')
j++;
temp1 = temp1->next;
}
printf("%d\t", i++);
printf("%s\t", temp->player_name);
printf("%d\n", j);
}
else
{
printf("%d\t", i++);
printf("%s\t", temp->player_name);
printf("0\n");
}
  temp = temp->next;
}
}
else
{
printf("There are no player\n");
}
return;
}
int main()
{
//adding only players name and teams
add_player("VIRAT KHOLI", "RCB");
add_player("ROHITH SHARMA", "MI");
add_player("MS DHONI", "CSK");
add_player("AB DEVILIERS", "RCB");
//adding matchs of players useing there position
//if player played give parameter has y else n
add_matchs("CSK VS RCB", 25, 1, 'y');
add_matchs("CSK VS RCB", 51, 4, 'y');
add_matchs("CSK VS MI", 99, 2, 'y');
add_matchs("CSK VS MI", 18, 3, 'y');
add_matchs("CSK VS MI", 0, 3, 'n');
add_matchs("RCB VS MI", 104, 1, 'y');
add_matchs("MI VS RCB", 17, 4, 'y');
add_matchs("RCB VS CSK", 74, 1, 'y');
add_matchs("RCB VS CSK", 27, 4, 'y');
add_matchs("RCB VS CSK", 0, 4, 'n');
add_matchs("KKR VS CSK", 77, 3, 'y');
add_matchs("MI VS CSK", 5, 2, 'y');
add_matchs("CSK VS MI", 65, 3, 'y');
add_matchs("KKR VS RCB", 87, 1, 'y');
add_matchs("CSK VS RCB", 95, 1, 'y');
add_matchs("KKR VS RCB", 0, 1, 'y');
add_matchs("CSK VS RCB", 0, 1, 'n');
display();
printf("===========================================================");
printf("\nThe player details who scored maximum runs in match ?\n");
max_runs("RCB VS MI");
printf("===========================================================\n");
printf("----------------------------------------------------------");
printf("\nThe number of matches played by each player ?\n");
total_matchs();
printf("----------------------------------------------------------");
return 0;
}
