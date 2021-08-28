#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <signal.h>
#include <fcntl.h>
#include "shell.h"

/**
 * main - Entry point to the custom shell program
 *
 * Return: 0 on success, -1 on failure
 *
 */
int main(void)
{
	char *line = NULL, *name, **tokens, **history;
	size_t length;
	ssize_t read;
	struct stat s;
	int i = 0, fd;

	history = malloc(sizeof(char *) * 1000);
	fd = open("/home/.simple_shell_history", O_RDWR | O_CREAT | O_APPEND);
	signal(SIGINT, sighandler);
	printprompt();
	while ((read = getline(&line, &length, stdin)) >= 0)
	{
		history[i] = _strdup(line);
		tokens = tokenize(line);
		if (tokens[0])
		{
			name = tokens[0];
			if (isbuiltin(tokens[0]))
			{
				if (_strcmp(tokens[0], "history") == 0)
					printhistory(history);
				else if (_strcmp(tokens[0], "exit") == 0)
					free(line), __exit(tokens, history, fd);
				else
					executebuiltin(tokens);
			}
			else
			{
				if (stat(tokens[0], &s) != 0)
					tokens[0] = check_path(tokens[0]);
				if (tokens[0])
					executecmd(tokens[0], tokens, NULL);
				else
					printf("%s: command not found\n", name);
			}
		}
		++i;
		printprompt();
	}
	return (0);
}

/**
 * printprompt - print the shell prompt
 *
 */
void printprompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("$ ");
}

/**
 * check_path - checks a file in the environment path
 *
 * @file: name of the file to check
 *
 * Return: full path of file
 *
 */
char *check_path(char *file)
{
	char *path, *temp;
	char *token;

	path = getenv("PATH");
	temp = _strdup(path);
	if (temp == NULL)
		return (NULL);
	token = strtok(temp, ":");
	while (token)
	{
		if (check_file(token, file))
		{
			_strcat(token, "/");
			_strcat(token, file);
			return (token);
		}
		token = strtok(NULL, ":");
	}
	free(temp);
	return (NULL);
}

/**
 * check_file - check if a file exist in a directory
 *
 * @dirname: directory name
 * @file: name of the file to check
 *
 * Return: 1 if success, 0 if failure
 */
int check_file(char *dirname, char *file)
{
	DIR *d;
	struct dirent *dir;

	d = opendir(dirname);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (_strcmp(dir->d_name, file) == 0)
			{
				closedir(d);
				return (1);
			}
		}
		closedir(d);
	}
	return (0);
}

/**
 * sighandler - handle the Ctrl+C signal
 *
 * @sig_n:
 *
 * Description: do not quit when the user presses Ctrl+C
 *
 */
void sighandler(int sig_n)
{
	(void) sig_n;
	fflush(stdout);
}
