if (strcmp(argv[0], "env") == 0)
		{
			int i = 0;

			while (envp[i])
			{
				printf("%s\n", envp[i]);
				i++;
			}

			free_argv(argv);
			line_number++;
			continue;
		}