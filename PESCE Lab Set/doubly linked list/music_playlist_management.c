#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure Declaration */

struct node
{
    int song_id;
    char title[50];
    char artist[50];
    float duration;

    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

/* Function to allocate memory for a node */

NODE getnode(void)
{
    NODE x;

    x = (NODE)malloc(sizeof(struct node));

    if(x == NULL)
    {
        printf("Out of memory..\n");
        exit(0);
    }

    return x;
}

/* Function to add a song at the rear-end */

NODE add_song(NODE first)
{
    NODE temp, cur;

    temp = getnode();

    printf("\nEnter Song ID: ");
    scanf("%d", &temp->song_id);

    printf("Enter Song Title: ");
    scanf(" %49[^\n]", temp->title);

    printf("Enter Artist Name: ");
    scanf(" %49[^\n]", temp->artist);

    printf("Enter Duration (in minutes): ");
    scanf("%f", &temp->duration);

    temp->rlink = temp->llink = NULL;

    if(first == NULL)
    {
        first = temp;
        printf("\nSong added successfully!\n");
        return first;
    }

    cur = first;

    while(cur->rlink != NULL)
    {
        cur = cur->rlink;
    }

    cur->rlink = temp;
    temp->llink = cur;

    printf("\nSong added successfully!\n");

    return first;
}

/* Function to delete a song based on Song ID */

NODE delete_song(NODE first)
{
    NODE cur;
    int id;

    if(first == NULL)
    {
        printf("\nPlaylist is Empty\n");
        return NULL;
    }

    printf("\nEnter Song ID to delete: ");
    scanf("%d", &id);

    cur = first;

    while(cur != NULL && cur->song_id != id)
    {
        cur = cur->rlink;
    }

    if(cur == NULL)
    {
        printf("\nSong not found!\n");
        return first;
    }

    /* If the first node is deleted */

    if(cur == first)
    {
        first = first->rlink;

        if(first != NULL)
        {
            first->llink = NULL;
        }
    }
    else
    {
        cur->llink->rlink = cur->rlink;

        if(cur->rlink != NULL)
        {
            cur->rlink->llink = cur->llink;
        }
    }

    printf("\nSong Deleted: %s\n", cur->title);

    free(cur);

    return first;
}

/* Function to display songs in forward order */

void display_forward(NODE first)
{
    NODE temp;

    if(first == NULL)
    {
        printf("\nPlaylist is Empty...\n");
        return;
    }

    printf("\nSongs in Forward Order:\n");

    for(temp = first; temp != NULL; temp = temp->rlink)
    {
        printf("\nSong ID: %d", temp->song_id);
        printf("\nTitle: %s", temp->title);
        printf("\nArtist: %s", temp->artist);
        printf("\nDuration: %.2f minutes\n", temp->duration);
    }
}

/* Function to display songs in reverse order */

void display_reverse(NODE first)
{
    NODE temp;

    if(first == NULL)
    {
        printf("\nPlaylist is Empty...\n");
        return;
    }

    temp = first;

    /* Move to the last node */

    while(temp->rlink != NULL)
    {
        temp = temp->rlink;
    }

    printf("\nSongs in Reverse Order:\n");

    /* Traverse from last node to first node */

    while(temp != NULL)
    {
        printf("\nSong ID: %d", temp->song_id);
        printf("\nTitle: %s", temp->title);
        printf("\nArtist: %s", temp->artist);
        printf("\nDuration: %.2f minutes\n", temp->duration);

        temp = temp->llink;
    }
}

/* Function to search songs based on title */

void search_song(NODE first)
{
    NODE cur;
    char search_title[50];
    int found = 0;

    if(first == NULL)
    {
        printf("\nPlaylist is Empty...\n");
        return;
    }

    printf("\nEnter Song Title to Search: ");
    scanf(" %49[^\n]", search_title);

    cur = first;

    while(cur != NULL)
    {
        if(strcmp(cur->title, search_title) == 0)
        {
            printf("\nSong Found!\n");

            printf("\nSong ID: %d", cur->song_id);
            printf("\nTitle: %s", cur->title);
            printf("\nArtist: %s", cur->artist);
            printf("\nDuration: %.2f minutes\n", cur->duration);

            found = 1;
        }

        cur = cur->rlink;
    }

    if(found == 0)
    {
        printf("\nSong not found!\n");
    }
}

/* Main Function */

int main()
{
    NODE first = NULL;
    int choice;

    for(;;)
    {
        printf("\n******** MUSIC PLAYLIST MANAGEMENT ********\n");

        printf("\n1: Add Song");
        printf("\n2: Delete Song Based on ID");
        printf("\n3: Display Songs in Forward Order");
        printf("\n4: Display Songs in Reverse Order");
        printf("\n5: Search Song by Title");
        printf("\n6: Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                first = add_song(first);
                break;

            case 2:
                first = delete_song(first);
                break;

            case 3:
                display_forward(first);
                break;

            case 4:
                display_reverse(first);
                break;

            case 5:
                search_song(first);
                break;

            case 6:
                printf("\nExiting Music Playlist...\n");
                exit(0);

            default:
                printf("\nInvalid choice...\n");
        }
    }

    return 0;
}
