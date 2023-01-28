/*
Reymond P. Yncierto
ST-1L

Create a program that implements a music playlist using linked lists that is sorted by playlist name. The program
must continue to run until the user picks exit.

Functionalities:
    1. Each playlist and song node is define by the structure.
    2. Must load each time the program run and save each time user picks exit.
        a. Save Data
        b. Load Data
    3. Menu
        a. Add Playlist
        b. Add Song to Playlist
        c. Remove Song from Playlist
        d. View a Playlist
        e. View all Data
        f. Exit
    4. Each choices except for the exit must be implemented inside a function
    5. Documentation
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song_tag { // structure definition
    char title[20];
    char artist[20];
    char album[20];
    struct song_tag *nextSong; 
} song;

typedef struct playlist_tag { // structure definition
    char name[50];
    int songCount;
    song *songHead;
    struct playlist_tag *next; 
} playlist;

void saveData(playlist **pHead) { // saves data to database "database.txt" 
    playlist *temp=*pHead ; // temp is a pointer to the head of the playlist
    if(temp==NULL) { // no data is found
        printf("\nNo data is saved in the database!\n");
        return ;
    } else { // at least one data is found
        FILE *fp=fopen("database.txt", "w");
        while (temp!=NULL) { // iterate playlist and save its details until it reaches the end
            fprintf(fp, "%d\n", temp->songCount);
            fprintf(fp, "%s\n", temp->name);
            song *tempSong=temp->songHead;
            while (tempSong!=NULL) { //iterate songs and store its details until it reaches the end
                fprintf(fp, "%s\n", tempSong->title);
                fprintf(fp, "%s\n", tempSong->artist);
                fprintf(fp, "%s\n", tempSong->album);
                tempSong=tempSong->nextSong; // move to the next song
            }
            temp=temp->next ;// move to the next playlist
        }
        printf("\nSuccessfully saved data!\n");
        fclose(fp); // close the file
    }
}

void loadData(playlist **pHead) { // loads data from the database "database.txt"
    FILE *fp=fopen("database.txt", "r"); // open the file
    if(fp==NULL) { // file is not found
        printf("\nFile not yet exists!\n\n");
        return ;
    } else { // file is found
    // load the data from the file
        printf("\nSuccessfully loaded data!\n\n");
        char tempName[50];
        int tempSongCount;
        char tempTitle[20];
        char tempArtist[20];
        char tempAlbum[20];
        while(!feof(fp)) {
            fscanf(fp, "%d\n", &tempSongCount);
            fscanf(fp, " %[^\n]s\n", tempName);
            playlist *tempPlaylist=malloc(sizeof(playlist)); 
            strcpy(tempPlaylist->name, tempName); // copy the details of the playlist
            tempPlaylist->songCount=tempSongCount; 
            tempPlaylist->songHead=NULL; // initialize songHead to NULL
            tempPlaylist->next=NULL; // initialize next to NULL
            if(*pHead==NULL) { // playlist head is empty
                *pHead=tempPlaylist; // assign new playlist to head of the playlist
            } else { // head of the playlist not empty
                playlist *temp=*pHead;
                while(temp->next!=NULL) { // iterate the playlist until it reaches the end
                    temp=temp->next;
                }
                temp->next=tempPlaylist; // assign new playlist to end of the playlist
            }
            for(int i=0; i<tempSongCount; i++) { // load the songs of the playlist
                fscanf(fp, " %[^\n]s\n", tempTitle);
                fscanf(fp, " %[^\n]s\n", tempArtist);
                fscanf(fp, " %[^\n]s\n", tempAlbum);
                song *tempSong=malloc(sizeof(song)); // copy the details of a song
                strcpy(tempSong->title, tempTitle);
                strcpy(tempSong->artist, tempArtist);
                strcpy(tempSong->album, tempAlbum);
                tempSong->nextSong=NULL;
                if(tempPlaylist->songHead==NULL) { // head of song is empty
                    tempPlaylist->songHead=tempSong; // assign new song to head of song
                } else { // head of song not empty
                    song *tempSong2=tempPlaylist->songHead;
                    while(tempSong2->nextSong!=NULL) { // iterate the song until it reaches the end
                        tempSong2=tempSong2->nextSong;
                    }
                    tempSong2->nextSong=tempSong; // assign new song to end of the song
                }
            }
        }
    }
    fclose(fp); // close the file
}

void addPlaylist(playlist **pHead) { // adds a new playlist
    playlist *newPlaylist=(playlist*)malloc(sizeof(playlist)); // allocate memory for the new playlist
    printf("\nEnter playlist name: "); // prompt user to enter playlist name
    scanf(" %[^\n]s", newPlaylist->name);
    for(playlist *temp=*pHead; temp!=NULL; temp=temp->next) { // iterate playlist and check if the playlist name already exists
        if(strcmp(temp->name, newPlaylist->name)==0) {
            printf("\nPlaylist name already exists!\n");
            return;
        }
    }
    playlist *temp=*pHead; 
    playlist *prev=NULL; 
    while (temp!=NULL && strcmp(temp->name, newPlaylist->name)>0) { // iterate playlist and check if the playlist name is greater than the new playlist name
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL) { // new playlist is the first playlist
        newPlaylist->next=*pHead;
        *pHead=newPlaylist;
    } else { 
        prev->next=newPlaylist;
        newPlaylist->next=temp;
    }
    printf("\nSuccessfully added playlist!\n");
}

void addSongToPlaylist(playlist **pHead) { // adds a song to a playlist
    if(*pHead==NULL) { // no playlist is found
        printf("\nNo playlist is found!\n");
        return;
    } else { // at least one playlist is found
        char playlistName[50]; 
        int i=1;
        printf("\nTHE PLAYLISTS AVAILABLE ARE:\n");
        for(playlist *cPlaylist = *pHead; cPlaylist != NULL; cPlaylist = cPlaylist->next) { // iterate and display playlists (alphabetical order)
            printf("    [%d] %s\n", i, cPlaylist->name);
            i++;
        }
        printf("\nEnter playlist name: "); // prompt user to enter playlist name
        scanf(" %[^\n]s", playlistName);
        playlist *temp=*pHead;
        while (temp!=NULL && strcmp(temp->name, playlistName)!=0) { // iterate playlist and check if the playlist name is found
            temp=temp->next;
        }
        if(temp==NULL) { // playlist name is not found
            printf("\nInvalid playlist!\n");
            return;
        } else { // playlist name is found
            song *newSong=(song*)malloc(sizeof(song)); // allocate memory for the new song
            printf("\nEnter song title: ");
            scanf(" %[^\n]s", newSong->title);
            printf("Enter song artist: ");
            scanf(" %[^\n]s", newSong->artist);
            printf("Enter song album: ");
            scanf(" %[^\n]s", newSong->album);
            song *tempSong=temp->songHead;
            song *prevSong=NULL;
            while (tempSong!=NULL && strcmp(tempSong->title, newSong->title)>0) { // iterate songs and check if the song title is greater than the new song title
                prevSong=tempSong;
                tempSong=tempSong->nextSong;
            }
            if(prevSong==NULL) { // new song is the first song
                newSong->nextSong=temp->songHead;
                temp->songHead=newSong;
            } else {
                prevSong->nextSong=newSong;
                newSong->nextSong=tempSong;
            }
            temp->songCount++; // increase the song count
            printf("\nSuccessfully added song to playlist!\n");
        }
    }
}

void removeSongFromPlaylist(playlist **pHead) { // removes a song from a playlist
    if(*pHead==NULL) { // if no playlist is found
        printf("\nThere are no playlists yet!\n");
    } else { // at least one playlist is found
        int i=1;
        playlist *temp=*pHead; // temp a pointer to head of the playlist
        printf("\nTHE PLAYLISTS AVAILABLE ARE:\n");
        while (temp!=NULL) { // iterate playlist
            printf("    [%d] %s\n", i, temp->name); // print the playlist name
            temp=temp->next; // move to the next playlist
            i++; 
        }
        char playlistName[50];
        printf("\nEnter playlist name: "); // get playlist name from user to remove song from
        scanf(" %[^\n]s", playlistName);
        temp=*pHead; // temp a pointer to head of the playlist
        while (temp!=NULL) { // iterate playlist
            if (strcmp(temp->name, playlistName)==0) { // check if the playlist name is found
                if(temp->songCount==0) { // check if there is song in the playlist
                    printf("\nPlaylist is still empty!\n");
                    return;
                } else {
                    int j=1;
                    song *tempSong=temp->songHead; // tempSong a pointer to head of the song
                    printf("\nTHE SONGS AVAILABLE ARE:\n");
                    while (tempSong!=NULL) { // iterate songs
                        printf("    [%d] %s by %s\n", j, tempSong->title, tempSong->artist); // print the song title
                        tempSong=tempSong->nextSong; // move to next song
                        j++; 
                    }
                    char songTitle[50];
                    char songArtist[50];
                    printf("\nEnter song title: "); // get song title from user to remove
                    scanf(" %[^\n]s", songTitle);
                    printf("Enter song artist: "); // get song title from user to remove
                    scanf(" %[^\n]s", songArtist);
                    tempSong=temp->songHead; // tempSong a pointer to head of the song
                    song *prevSong=NULL; // prevSong a pointer to previous song
                    while (tempSong!=NULL) { // iterate songs
                        if (strcmp(tempSong->title, songTitle)==0 && strcmp(tempSong->artist, songArtist)==0) { // check if both song title and song artist exists
                            break;
                        }
                        prevSong=tempSong; // assign previous song to tempSong
                        tempSong=tempSong->nextSong; // move to the next song
                    }
                    if (tempSong==NULL) { // if the song title is not found
                        printf("\nSong not found!\n");
                        return;
                    } else { // if the song title is found
                        if (prevSong==NULL) { // if the song is the first song
                            temp->songHead=tempSong->nextSong; 
                        } else { // if the song is not the first song
                            prevSong->nextSong=tempSong->nextSong; // assign next song to the previous song
                        }
                        free(tempSong); // free the song
                        temp->songCount--; // decrease the song count
                        printf("\nSuccessfully deleted song!\n");
                        return;
                    }
                }
            }
            temp=temp->next; // move to the next playlist
        }
        printf("\nInvalid playlist!\n");
    }
}

void viewPlaylist(playlist **pHead) { // view a playlist
    if(*pHead == NULL) { // if no playlist is found
        printf("\nThere are no playlists yet!\n");
    } else { // at least one playlist is found
        int i=1;
        playlist *temp=*pHead; // temp a pointer to the head of the playlist
        printf("\nTHE PLAYLISTS AVAILABLE ARE:\n");
        while (temp!=NULL) { // iterate playlist
            printf("    [%d] %s\n", i, temp->name);
            temp=temp->next; // move to the next playlist
            i++; 
        }
        char playlistName[50];
        printf("\nEnter playlist name: "); // get playlist name from user to view
        scanf(" %[^\n]s", playlistName);
        temp=*pHead; // temp a pointer to head of the playlist
        while (temp!=NULL) { // iterate playlist
            if (strcmp(temp->name, playlistName)==0) { // check if the playlist name is found
                if(temp->songCount==0) { // check if there is song in the playlist
                    printf("\nPlaylist is still empty!\n");
                    return;
                } else { 
                    printf("\nPLAYLIST: %s\n", temp->name); // print playlist name
                    printf("SONG COUNT: %d\n", temp->songCount); // print song count
                    song *tempSong=temp->songHead;
                    while (tempSong!=NULL) { // iterate songs
                        printf("    SONG TITLE: %s\n", tempSong->title); // print the song title
                        printf("    SONG ARTIST: %s\n", tempSong->artist); // print the song artist
                        printf("    SONG ALBUM: %s\n", tempSong->album); // print the song album
                        if(tempSong->nextSong!=NULL) {
                            printf("\n");
                        }
                        tempSong=tempSong->nextSong; // move to the next song
                    }
                    return;
                }
            }
            temp=temp->next; // move to the next playlist
        }
        printf("\nInvalid playlist!\n");
    }
}

void viewAllData(playlist **pHead) { // view all data
    if(*pHead==NULL) { // if no playlist is found
        printf("\nThere are no playlist yet!\n");
    } else { // at least one playlist is found
        for(playlist *temp = *pHead; temp != NULL; temp = temp->next) { // iterate playlist and display (alphabetical order) all their details
            printf("\nPLAYLIST: %s\n", temp->name);
            printf("SONG COUNT: %d\n", temp->songCount);
            for(song *temp2 = temp->songHead; temp2 != NULL; temp2 = temp2->nextSong) { // iterate and display songs (alphabetical order) and their details
                printf("    SONG TITLE: %s\n", temp2->title);
                printf("    SONG ARTIST: %s\n", temp2->artist);
                printf("    SONG ALBUM: %s\n", temp2->album);
                if(temp2->nextSong != NULL) {
                    printf("\n");
                }
            }
        }
    }
}

int main() {
    playlist *pHead = NULL; 
    int choice;
    loadData(&pHead); // load data from file
    while(1) {
        printf("======= MENU =======\n");
        printf("[1] Add Playlist\n");
        printf("[2] Add Song to Playlist\n");
        printf("[3] Remove Song from Playlist\n");
        printf("[4] View a Playlist\n");
        printf("[5] View All Data\n");
        printf("[6] Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addPlaylist(&pHead); // add playlist
                break;
            case 2:
                addSongToPlaylist(&pHead); // add song to playlist
                break;
            case 3:
                removeSongFromPlaylist(&pHead); // remove song from playlist
                break;
            case 4:
                viewPlaylist(&pHead); // view playlist
                break;
            case 5:
                viewAllData(&pHead); // view all data
                break;
            case 6:
                saveData(&pHead); // save data to file
                printf("\nThank you for using this program!\n");
                return 0;
        }
        printf("------------------------------\n");
    }
}