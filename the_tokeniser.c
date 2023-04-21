#include "main.h"

char **the_tokeniser(char *cmd, char *delim)
{
	char **tokens;
	char *tmp, *cmd_cp;
	int args = 0, len = 0, i = 1;

	if (!cmd)
		return (NULL);
	cmd_cp = stringcpy(cmd);
	args = no_of_args(cmd, delim);
	tokens = malloc(sizeof(char *) * (args + 1)); /* +1 for null*/
	
	if (!tokens)
		return (NULL);
	 tmp = strtok(cmd_cp, delim);
	 tokens[0] = tmp;
	while (tmp != NULL) /* (i = 1; i < args; i++)*/
	{
		len = 0;
		tmp = strtok(NULL, delim);
		len = stringlen(tmp);
		tokens[i] = malloc(sizeof(char) * (len + 1));
		if (!tokens[i])
			return (NULL);
		
		tokens[i] = tmp;	
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
