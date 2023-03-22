/*
** EPITECH PROJECT, 2022
** alphanum
** File description:
** alphanum
*/

int alphanum(int const str)
{
    if ((str >= 48 && str <= 57) || (str >= 65 && str <= 90))
        return (1);
    if (str >= 97 && str <= 122)
        return (1);
    if (str == -61 || str == -15446 || str == -15445 || str == -15448)
        return (1);
    return (0);
}
