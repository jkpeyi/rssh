#include <stdio.h>
#include <stdlib.h>
#include "command.h"
#include <string.h>

void add_host(const Host *host) {
    FILE *configFile;

    configFile = fopen(CONFIG_FILE, "a");
    if (configFile == NULL) {
        printf("Error opening the configuration file.\n");
        exit(1);
    }

    fprintf(configFile, "%s %s %s\n", host->name, host->host_ip , host->password);
    fclose(configFile);
}



void handle_command(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: rssh <command> <[params]> \n");
        exit(1);
    }

    if (strcmp(argv[1], "add") == 0) {



        Host host;
        strcpy(host.name, argv[2]);

        printf("Enter the host IP: \n ");

        scanf("%s", host.host_ip);

        printf("Enter the host password: \n ");

        scanf("%s", host.password);


        add_host(&host);

        exit(0);
    }

    //by default continue with list

   // printf("Unknown command: %s\n", argv[1]);
   // exit(1);
}