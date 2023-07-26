#include "deck.h"

/**
 * _strcmp - Compares two strings.
 * @s1: the initial string being compared.
 * @s2: comparing the second string.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }

    if (*s1 != *s2)
        return (*s1 - *s2);
    return 0;
}

/**
 * get_value - Obtain a card's numerical value.
 * @card: a deck_node_t card pointer.
 *
 * Return: The card's numerical value.
 */
char get_value(deck_node_t *card)
{
    if (_strcmp(card->card->value, "Ace") == 0)
        return 0;
    if (_strcmp(card->card->value, "1") == 0)
        return 1;
    if (_strcmp(card->card->value, "2") == 0)
        return 2;
    if (_strcmp(card->card->value, "3") == 0)
        return 3;
    if (_strcmp(card->card->value, "4") == 0)
        return 4;
    if (_strcmp(card->card->value, "5") == 0)
        return 5;
    if (_strcmp(card->card->value, "6") == 0)
        return 6;
    if (_strcmp(card->card->value, "7") == 0)
        return 7;
    if (_strcmp(card->card->value, "8") == 0)
        return 8;
    if (_strcmp(card->card->value, "9") == 0)
        return 9;
    if (_strcmp(card->card->value, "10") == 0)
        return 10;
    if (_strcmp(card->card->value, "Jack") == 0)
        return 11;
    if (_strcmp(card->card->value, "Queen") == 0)
        return 12;
    return 13;
}

/**
 * insertion_sort_deck_kind - From spades to diamonds, order a deck of cards..
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
    deck_node_t *iter, *insert, *tmp;

    for (iter = (*deck)->next; iter != NULL; iter = tmp)
    {
        tmp = iter->next;
        insert = iter->prev;
        while (insert != NULL && insert->card->kind > iter->card->kind)
        {
            insert->next = iter->next;
            if (iter->next != NULL)
                iter->next->prev = insert;
            iter->prev = insert->prev;
            iter->next = insert;
            if (insert->prev != NULL)
                insert->prev->next = iter;
            else
                *deck = iter;
            insert->prev = iter;
            insert = iter->prev;
        }
    }
}

/**
 * insertion_sort_deck_value - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: a pointer to the top of a doubly-linked list called deck_node_t.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
    deck_node_t *iter, *insert, *tmp;

    for (iter = (*deck)->next; iter != NULL; iter = tmp)
    {
        tmp = iter->next;
        insert = iter->prev;
        while (insert != NULL &&
               insert->card->kind == iter->card->kind &&
               get_value(insert) > get_value(iter))
        {
            insert->next = iter->next;
            if (iter->next != NULL)
                iter->next->prev = insert;
            iter->prev = insert->prev;
            iter->next = insert;
            if (insert->prev != NULL)
                insert->prev->next = iter;
            else
                *deck = iter;
            insert->prev = iter;
            insert = iter->prev;
        }
    }
}

/**
 * sort_deck - Sort the cards in a deck from ace to king, and
 *             between spades and diamonds.
 * @deck: a pointer to the top of a doubly-linked list called deck_node_t.
 */
void sort_deck(deck_node_t **deck)
{
    if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
        return;

    insertion_sort_deck_kind(deck);
    insertion_sort_deck_value(deck);
}
