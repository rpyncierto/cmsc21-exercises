/*
Reymond P. Yncierto
ST-1L

Create a program that implements a music playlist using structures and files. The program must continue to run until the user picks exit

Functionalities:
    1. Two structures for playlist and song.
    2. Loads the data each time it is ran and saves data each time user picks exit.
    3. Menu for user to pick options.
        3.1. Add playlist
        3.2. Add song to playlist.
        3.3. Remove song from playlist.
        3.4. View a playlist.
        3.5. View all data.
        3.6. Exit.
    4. Each choices must be implemented in a function except for the exit. Saving and loading data must also be inside a function.
*/
#include <stdio.h>
#include <string.h>

typedef struct song { // structure definition
    char title[100];
    char artist[100];
    char album[100];
} music;

typedef struct playlist { // structure definition
    char name[100];
    int songCount;
    music song[10];
} songlist;

void loadData(songlist *playlistArray, int *i) {
    FILE *fp = fopen("database.txt", "r"); // open the database.txt file for reading
    if(fp == NULL) { // file is not yet created
        printf("File not yet exists!\n\n");
        return;
    } else { // file is existing
        fscanf(fp, "%d\n", i); // scan the number of playlist
        for(int j=0; j<*i; j++) { // scan the file until the number of playlist and get their corresponding name and song count
        fscanf(fp, "\n%[^\n]s", playlistArray[j].name);
        fscanf(fp, "%d\n", &playlistArray[j].songCount);        
        for(int k=0; k<playlistArray[j].songCount; k++) { // scan the file until the number of songs in each playlist and get their corresponding title, artist, and album
            fscanf(fp, "\n%[^\n]s", playlistArray[j].song[k].title);
            fscanf(fp, "\n%[^\n]s", playlistArray[j].song[k].artist);
            fscanf(fp, "\n%[^\n]s\n", playlistArray[j].song[k].album);
            }
        }
        fclose(fp); // close the file
        printf("Successfully loaded data!\n\n");       
    }
}

void saveData(songlist *playlistArray, int i) {
    FILE *fp = fopen("database.txt", "w"); // open the file database.txt for writing; w since we need to replace the information in the file every time there are changes made
    if(fp == NULL) { // if previous data is not changed or there is no changes in the data
        printf("No data to saved in the database!\n");
        return ;
    } else { // changes have been made
        fprintf(fp, "%d\n", i); // store the number of playlist
        for(int j=0; j<i; j++) { // iterate through the playlist array then print their corresponding name and song count
            fprintf(fp, "%s\n", playlistArray[j].name);
            fprintf(fp, "%d\n", playlistArray[j].songCount);       
            for(int k=0; k<playlistArray[j].songCount; k++) { // iterate through the song array of the playlist being printed and print their corresponding title, artist, and album
                fprintf(fp, "%s\n", playlistArray[j].song[k].title);
                fprintf(fp, "%s\n", playlistArray[j].song[k].artist);
                fprintf(fp, "%s\n", playlistArray[j].song[k].album);
            } 
        }
        printf("\nSuccessfully saved data!\n");
        fclose(fp); // close the file
    }
}

void addPlaylist(songlist *playlistArray, int *i) { // 
    char name[100];
    if(*i==10) { // if there are already 10 playlist
        printf("\nThere isn't enough room for another playlist!\n");
        return;
    } else { // if there is room for another playlist
        printf("\nEnter playlist name: "); // get playlist name from the user
        scanf(" %[^\n]s", name);
        for(int j=0; j<*i; j++) { // iterate the playlist array
            if(strcmp(playlistArray[j].name, name) == 0) { // if there exist the same playlist name given by the user and is also existing in the database
                printf("\nPlaylist name already exists!\n");
                return;
            }
        } // playlist name is available
        strcpy(playlistArray[*i].name, name); // copy the playlist name to the playlist array assigned to the free index
        playlistArray[*i].songCount = 0; // initialize its song count to 0
        printf("\nSuccessfully added playlist!\n");
        (*i)++; // increment i means there is a playlist added
    }  
}

void addSongToPlaylist(songlist *playlistArray, int i) {
    if(i==0) { // no playlist is found in the database
        printf("\nThere are no playlist yet!\n");
    } else { // there is at least 1 playlist found in the database
        int choice;
        printf("\nTHE PLAYLISTS AVAILABLE ARE:\n");
        for(int j=0; j<i; j++) { // iterate the playlist array then print their names
            printf("    [%d] %s\n", j, playlistArray[j].name);
        }
        printf("\nEnter playlist number: "); // get playlist number from the user where to add song
        scanf("%d", &choice);
        if(choice>=i || choice<0) { // if playlist number is not in the range of the playlist array
            printf("\nInvalid playlist!\n");
        } else if(playlistArray[choice].songCount>=10) { // if song count from the playlist chosen by the user is already 10 (full)
                printf("\nThere isn't enough room for another song!\n");
        } else { // there is a free room for a song in the playlist
            char title[100];
            char artist[100];
            char album[100];
            printf("\nEnter song title: "); // get song title from the user
            scanf(" %[^\n]s", title);
            printf("Enter song artist: "); // get song artist from the user
            scanf(" %[^\n]s", artist);
            printf("Enter song album: "); // get song album from the user
            scanf(" %[^\n]s", album);
            for(int j=0; j<playlistArray[choice].songCount; j++) { // iterate the song array in the playlist chosen by the user
                if(strcmp(playlistArray[choice].song[j].title, title) == 0) { // check if song name exists in the song array of the playlist chosen by the user
                    printf("\nSong already exists!\n");
                    return;
                }
            } // song name not yet added
            strcpy(playlistArray[choice].song[playlistArray[choice].songCount].title, title); // copy the song title to the song array of the playlist chosen by the user
            strcpy(playlistArray[choice].song[playlistArray[choice].songCount].artist, artist); // copy the song artist to the song array of the playlist chosen by the user
            strcpy(playlistArray[choice].song[playlistArray[choice].songCount].album, album); // copy the song album to the song array of the playlist chosen by the user
            playlistArray[choice].songCount++; // increment the song count of the playlist chosen by the user
            printf("\nSuccessfully added song to playlist!\n");
        }
    }
}

void removeSongFromPlaylist(songlist *playlistArray, int i) {
    if(i==0) { // no playlist is found in the database 
        printf("\nThere are no playlists yet!\n");
        return;
    } else { // there is at least 1 playlist found in the database
        int choice;
        printf("\nTHE PLAYLISTS AVAILABLE ARE:\n");
        for(int j=0; j<i; j++) { // iterate the playlist array then print their names
            printf("    [%d] %s\n", j, playlistArray[j].name);
        }
        printf("\nEnter playlist number: "); // get playlist number from the user where to add song
        scanf("%d", &choice);
        if(choice>=i || choice<0) { // if playlist number is not in the range of the playlist array
            printf("\nInvalid playlist!\n");
        } else if(playlistArray[choice].songCount==0) { // if there is no song in the playlist chosen by the user
            printf("Playlist is still empty!\n");
            return;
        } else { // there is at least 1 song in the playlist chosen by the user
            int num;
            printf("\nTHE SONGS AVAILABLE ARE:\n");
            for(int j=0; j<playlistArray[choice].songCount; j++) { // iterate the song array in the playlist chosen by the user then print corresponding number, title and the artist of each song 
                printf("    [%d] %s by %s\n", j, playlistArray[choice].song[j].title, playlistArray[choice].song[j].artist); 
            }
            printf("\nEnter song number to delete: "); // get song number from the user to delete the song that corresponds to it
            scanf("%d", &num);
            if(num>playlistArray[choice].songCount-1 || num<0) { // if song number not in the range of the song array in the playlist chosen by the user
                printf("Invalid song number!\n");
                return;
            } else { // song number is in the range of the song array in the playlist chosen by the user
                for(int j=num; j<playlistArray[choice].songCount; j++) { // iterate the song array in the playlist chosen by the user and shift all the songs after the song chosen by the user to the left
                    strcpy(playlistArray[choice].song[j].title, playlistArray[choice].song[j+1].title);
                    strcpy(playlistArray[choice].song[j].artist, playlistArray[choice].song[j+1].artist);
                    strcpy(playlistArray[choice].song[j].album, playlistArray[choice].song[j+1].album);
                }
                playlistArray[choice].songCount--; // decrement the song count of the playlist chosen by the user
                printf("Successfully deleted song!\n");
                return;
            }
        }    
    }       
}

void viewPlaylist(songlist *playlistArray, int i) {
    if(i==0) { // no playlist is found in the database 
        printf("\nThere are no playlists yet!\n");
    } else { // there is at least 1 playlist found in the database
        int choice;
        printf("\nTHE PLAYLISTS AVAILABLE ARE:\n"); 
        for(int j=0; j<i; j++) { // iterate the playlist array then print their names
            printf("    [%d] %s\n", j, playlistArray[j].name);
        }
        printf("\nEnter playlist number: "); // get playlist number from the user where to view the songs
        scanf("%d", &choice);
        if(choice>i-1 || choice<0) { // if playlist number is not in the range of the playlist array
            printf("\nInvalid playlist!\n");
        } else { // playlist number is in the range of the playlist array
            printf("\nPLAYLIST: %s\n", playlistArray[choice].name); // print the playlist name
            printf("SONG COUNT: %d\n", playlistArray[choice].songCount); // print the song count of the playlist
            for(int j=0; j<playlistArray[choice].songCount; j++) { // iterate the song array in the playlist chosen by the user then print their corresponding title, artist and album of each song
                printf("    SONG TITLE: %s\n", playlistArray[choice].song[j].title);
                printf("    SONG ARTIST: %s\n", playlistArray[choice].song[j].artist);
                printf("    SONG ALBUM: %s\n", playlistArray[choice].song[j].album);
                if(j!=playlistArray[choice].songCount-1) { // for readability in the terminal
                    printf("\n");
                }
            }
        }
    }
}

void viewAllData(songlist *playlistArray, int i) {
    if(i==0) { // no playlist is found in the database 
        printf("\nThere are no playlists yet!\n");
    } else { // there is at least 1 playlist found in the database
        for(int j=0; j<i; j++) { // iterate the playlist array then print their corresponding names and song count
            printf("\nPLAYLIST: %s\n", playlistArray[j].name);
            printf("SONG COUNT: %d\n", playlistArray[j].songCount);  
            for(int k=0; k<playlistArray[j].songCount; k++) { // iterate the song array of each playlist in the playlist array then print corresponding title, artist and album of each song
                printf("    SONG TITLE: %s\n", playlistArray[j].song[k].title);
                printf("    SONG ARTIST: %s\n", playlistArray[j].song[k].artist);
                printf("    SONG ALBUM: %s\n", playlistArray[j].song[k].album);
                if(k!=playlistArray[j].songCount-1) { // for readability in the terminal
                    printf("\n");
                }
            }
        }
    }
}

int main() {
    songlist playlist[10]; // structure declaration
    int choice, i=0;
    loadData(playlist, &i); // load data from database
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
                addPlaylist(playlist, &i); // add a playlist
                break;
            case 2:
                addSongToPlaylist(playlist, i); // add song to a playlist
                break;
            case 3:
                removeSongFromPlaylist(playlist, i); // remove a song from playlist
                break;
            case 4:
                viewPlaylist(playlist, i); // view a playlist
                break;
            case 5:
                viewAllData(playlist, i); // view all data
                break;
            case 6: 
                saveData(playlist, i); // save data to the database
                printf("\nThank you for using this program!\n");
                return 0;
        }
        printf("------------------------------\n");
    } 
}

