#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <readline/readline.h>

# define BUFFSIZE 512
# define LINESIZE 1024

// bu enumda benim turleri tutugum yer maskelemek kolay olmasi icin
// 2 nin katlari ile islem yapiyorum
typedef enum e_kind {
    CMD = 0,
    PIPE = 1,
    REDIRECT = 2,
    ARG = 4,
    QUOTE = 8,
} e_kind;

// cmd ile readline ile donen yazilari tutuyorum ve 
// bunlari splitliyorum ve onuda ** icerisinde tutuyorum
typedef struct s_input{
    char *line;
    char **splited_line;
} t_input;

//Burasi benim cmd.splited_line dan algim ve artik kimliklerini aktardigim yer
//cift yonlu bagli liste ile bunlari burada tutuyorum ve hepsine birer id veriyorum
typedef struct s_cmdline{
    int index;
    struct s_cmdline *next;
    struct s_cmdline *prev;
    e_kind type;
    char *value;
} t_cmdline;

// pwd enviroment ini tutan structim
typedef struct s_pwd{
    char *line;
}   t_pwd;

// Ana struct yapim
typedef struct s_shell{
    t_pwd pwd;
    t_input input;
    t_cmdline *cmdline;
    char **history;
} t_shell;

/********init********/
void   ft_mshell_loop(t_shell **shell, char **envp);
void ft_parse_pwd(t_shell **shell, char **envp);

/*****history.c*****/
void ft_save_history(t_shell **shell, const char *line);

// ***
void new_history(t_shell **shell, char *line);
// ***

/******lexer**********/
void ft_space_split(t_shell **shell);
char **alphabet_parser(char *str);

/******utils**********/
char *ft_strstr(const char *s1, const char del);
size_t ft_strnlen(const char *s1, const char del);
void ft_error(const char *err);
int ft_check_type(t_shell **shell, char *line);

/****check_operations***/
int check_greater_than(t_cmdline **root, char **line);
int less_than(t_cmdline **root, char **line);

/*********lst**********/
void cmdline_addlst_back(t_cmdline **lst, t_cmdline *newlst);
t_cmdline *cmdline_new_list(char *word, int type, t_shell **shell);
void addlst_lexer(t_cmdline **cmd, t_shell **shell, size_t size);
void ft_free_list(t_cmdline **cmd);

#endif
