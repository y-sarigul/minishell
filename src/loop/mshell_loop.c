#include "../../inc/minishell.h"
#include <stdio.h>

// list unit test
// static void ft_printlst(t_shell **shell)
// {
//     t_cmdline *iter;

//     iter = (*shell) ->cmdline;
//     while (iter)
//     {
//         printf("%s\n", iter -> value);
//         iter = iter -> next;
//     }
// }
//
//
//indexleri stdout'a yazdirmak icin kullaniyorum
//kontrol amacli
void ft_print_index(t_cmdline *root)
{
    while (root)
    {
        printf("%d\n", root->index);
        root = root -> next;
    }
}

void ft_print_anyone_index(t_cmdline *root, int index)
{
    int i;

    i = 0;

    while (i < index)
    {
        root = root -> next;
        i++;
    }
    printf("%s\n", root -> value);
}

/*
 * Burasi benim ana while dongum ve burada programin dongusu soz konusudur
 * Burada yapilan islemler sirasi ile 
 * $PWD ve $USER environmentlarini parslayarak pwd nin son indexini ve 
 * Hangi kullanici kullaniyorsa unun user idsini alarak 
 * bunu loop icerisinde kullniyorum
 * Ornek olarak
 * msarigul@minishell => 
 * sonraki islemde readline kutuphanesini kullanarak readline fonksiyonunu
 * gonderiyorum ve buradan gelen char *buff i historiye kayit ediyorum 
 * Ondan sonra ft_space_split ile kontrollerimi ve yapilacak islemleri yapiyorum.
 *
 * */
void ft_mshell_loop(t_shell **shell, char **envp)
{
    while (1){
        ft_parse_pwd(shell, envp);
        printf("%s => ", (*shell) -> pwd.line);
        (*shell) -> input.line = readline("");
        new_history(shell, (*shell)->input.line);
        ft_space_split(shell);
        ft_print_index((*shell)->cmdline);
        //ft_print_anyone_index((*shell)->cmdline, 2);
        ft_free_list(&(*shell)->cmdline);
    }
}
