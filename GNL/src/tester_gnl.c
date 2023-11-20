/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:19:48 by cnatanae          #+#    #+#             */
/*   Updated: 2023/11/20 14:08:50 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_gnl.h"

MU_TEST(test_gnl_passing_empy_file)
{
	int fd;
	char *expected_result;
	char *result;
	fd = open ("includes/texts/5-empty.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file - test 1");
		exit(1);
	}
	result = get_next_line(fd);
	expected_result = NULL;
	mu_assert_string_eq(expected_result, result);
	close(fd);
	free(result);
}

MU_TEST(test_gnl_passing_one_char)
{
	int fd;
	char expected_result[3] = "z\n\0";
	char *result;
	
	fd = open ("includes/texts/7-onechar.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file test 2");
		exit(1);
	}
	result = get_next_line(fd);
	close(fd);
	mu_assert_string_eq(expected_result, result);
	free(result);
}

MU_TEST(test_gnl_passing_bigben)
{
	char	*expected_result;
	char	*result;
	char	line[1024];
	int		fd;
	FILE	*file;

	file = fopen("includes/texts/12-bigben.txt", "r");
	fd = open ("includes/texts/12-bigben.txt", O_RDONLY);
	if ( !file ||fd == -1)
	{
		perror("Error opening file test 3");
		close(fd);
		fclose(file);
		exit(1);
	}
	while(1)
	{
		result = get_next_line(fd);
		expected_result = fgets(line, sizeof(line), file);
		if (expected_result == NULL && result == NULL)
		{
			mu_assert_int_eq(1, 1);
			break;
		}
		else if (expected_result == NULL && result != NULL)
		{
			mu_assert_int_eq(1, 2);
			free(result);
			break;
		}
		else if (strcmp(expected_result, result) != 0)
		{
			mu_assert_int_eq(1, 2);
			free(result);
			break;
		}
		free(result);
	}
	close(fd);
	fclose(file);
}

MU_TEST(test_gnl_passing_marge_top)
{
	char	*expected_result;
	char	*result;
	char	line[1024];
	int		fd;
	FILE	*file;

	file = fopen("includes/texts/half_marge_top.txt", "r");
	fd = open ("includes/texts/half_marge_top.txt", O_RDONLY);
	if ( !file ||fd == -1)
	{
		perror("Error opening file test 4");
		exit(1);
	}
	while(1)
	{
		result = get_next_line(fd);
		expected_result = fgets(line, sizeof(line), file);
		if (expected_result == NULL && result == NULL)
		{
			mu_assert_int_eq(1, 1);
			break;
		}
		else if (expected_result == NULL && result != NULL)
		{
			mu_assert_int_eq(1, 2);
			free(result);
			break;
		}
		else if (strcmp(expected_result, result) != 0)
		{
			mu_assert_int_eq(1, 2);
			free(result);
			break;
		}
		free(result);
	}
	close(fd);
	fclose(file);
}

MU_TEST(test_gnl_passing_marge_bottom)
{
	char	*expected_result;
	char	*result;
	char	line[1024];
	int		fd;
	FILE	*file;

	file = fopen("includes/texts/half_marge_bottom.txt", "r");
	fd = open ("includes/texts/half_marge_bottom.txt", O_RDONLY);
	if ( !file ||fd == -1)
	{
		perror("Error opening file test 5");
		exit(1);
	}
	while(1)
	{
		result = get_next_line(fd);
		expected_result = fgets(line, sizeof(line), file);
		if (expected_result == NULL && result == NULL)
		{
			mu_assert_int_eq(1, 1);
			break;
		}
		else if (expected_result == NULL && result != NULL)
		{
			mu_assert_int_eq(1, 2);
			free(result);
			break;
		}
		else if (strcmp(expected_result, result) != 0)
		{
			mu_assert_int_eq(1, 2);
			free(result);
			break;
		}
		free(result);
	}
	close(fd);
	fclose(file);
}

MU_TEST(test_gnl_passing_aleatory_lines)
{
	int		fd;
	char	*expected_result;
	char	*result;
	char	line[1024];
	int		i;
	FILE	*file;

	i = 0;
	file = fopen("includes/texts/aleatory_lines.txt", "r");
	fd = open("includes/texts/aleatory_lines.txt", O_RDONLY);
	if ( !file ||fd == -1)
	{
		perror("Error opening file test 6");
		exit(1);
	}
	while(1)
	{
		result = get_next_line(fd);
		expected_result = fgets(line, sizeof(line), file);
		if (expected_result == NULL && result == NULL)
		{
			mu_assert_int_eq(1, 1);
			break;
		}
		else if (expected_result == NULL && result != NULL)
		{
			mu_assert_int_eq(1, 2);
			free(result);
			break;
		}
		else if (strcmp(expected_result, result) != 0)
		{
			mu_assert_int_eq(1, 2);
			free(result);
			break;
		}
		free(result);
	}
	close(fd);
	fclose(file);
}

MU_TEST(test_gnl_passing_gnl_file)
{
	int		fd;
	char	*expected_result;
	char	*result;
	char	line[1024];
	FILE	*file;

	file = fopen("src/minunit.h", "r");
	fd = open("src/minunit.h", O_RDONLY);
	if ( !file ||fd == -1)
	{
		perror("Error opening file test 7");
		exit(1);
	}
	while(1)
	{
		result = get_next_line(fd);
		expected_result = fgets(line, sizeof(line), file);
		if (expected_result == NULL && result == NULL)
		{
			mu_assert_int_eq(1, 1);
			break;
		}
		else if (expected_result == NULL && result != NULL)
		{
			mu_assert_int_eq(1, 2);
			free(result);
			break;
		}
		else if (strcmp(expected_result, result) != 0)
		{
			mu_assert_int_eq(1, 2);
			free(result);
			break;
		}
		free(result);
	}
	close(fd);
	fclose(file);
}

MU_TEST(test_gnl_passing_alphabet_file)
{
	int fd;
	char *expected_result;
	char *result;
	char line[1024];
	FILE *file;

	file = fopen("includes/texts/alphabet.txt", "r");
	fd = open("includes/texts/alphabet.txt", O_RDONLY);
	if (!file || fd == -1)
	{
		perror("Error opening alphabet.txt");
		exit(1);
	}
	while (1)
	{
		result = get_next_line(fd);
		expected_result = fgets(line, sizeof(line), file);
		if (expected_result == NULL && result == NULL)
		{
			mu_assert_int_eq(1, 1);
			break;
		}
		else if (expected_result == NULL && result != NULL)
		{
			mu_assert_int_eq(1, 2);
			free(result);
			break;
		}
		else if (strcmp(expected_result, result) != 0)
		{
			mu_assert_int_eq(1, 2);
			free(result);
			break;
		}
		free(result);
	}
	close(fd);
	fclose(file);
}

MU_TEST_SUITE(Get_next_line_tester)
{
	MU_RUN_TEST(test_gnl_passing_empy_file);
	MU_RUN_TEST(test_gnl_passing_one_char);
	MU_RUN_TEST(test_gnl_passing_bigben);
	MU_RUN_TEST(test_gnl_passing_marge_top);
	MU_RUN_TEST(test_gnl_passing_marge_bottom);
	MU_RUN_TEST(test_gnl_passing_aleatory_lines);
	MU_RUN_TEST(test_gnl_passing_gnl_file);
	MU_RUN_TEST(test_gnl_passing_alphabet_file);
}

int	main(void)
{
	MU_RUN_SUITE(Get_next_line_tester);
	MU_REPORT();
	return MU_EXIT_CODE;
}