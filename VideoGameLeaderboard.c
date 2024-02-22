// Program to manage a video game leaderboard by reading from and writing to text and binary files.
// Uses file I/O operations to store player data.
// Customized player names are used for added fun.

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

// Define a structure to represent a player
struct Player {
    char name[MAX_NAME_LENGTH];
    int score;
};

// Function to read player data from a text file
void readTextFile(const char *filename) {
    struct Player player;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("Leaderboard (from text file):\n");
    while (fscanf(file, "%s %d", player.name, &player.score) != EOF) {
        printf("Player: %s, Score: %d\n", player.name, player.score);
    }
    fclose(file);
}

// Function to read player data from a binary file
void readBinaryFile(const char *filename) {
    struct Player player;
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("\nLeaderboard (from binary file):\n");
    while (fread(&player, sizeof(struct Player), 1, file) == 1) {
        printf("Player: %s, Score: %d\n", player.name, player.score);
    }
    fclose(file);
}

// Function to write player data to a text file
void writeTextFile(const char *filename) {
    struct Player players[] = {
        {"Ninja", 100},
        {"Shadow", 150},
        {"Dragon", 200}
    };
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("\nWriting leaderboard to text file...\n");
    for (int i = 0; i < sizeof(players) / sizeof(players[0]); i++) {
        fprintf(file, "%s %d\n", players[i].name, players[i].score);
    }
    fclose(file);
}

// Function to write player data to a binary file
void writeBinaryFile(const char *filename) {
    struct Player players[] = {
        {"Mystic", 250},
        {"Elven", 300},
        {"Dwarven", 350}
    };
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("\nWriting leaderboard to binary file...\n");
    fwrite(players, sizeof(struct Player), sizeof(players) / sizeof(players[0]), file);
    fclose(file);
}

int main() {
    const char *textFilename = "leaderboard.txt";
    const char *binaryFilename = "leaderboard.bin";

    // Write player data to text and binary files
    writeTextFile(textFilename);
    writeBinaryFile(binaryFilename);

    // Read player data from text and binary files
    readTextFile(textFilename);
    readBinaryFile(binaryFilename);

    return 0;
}
