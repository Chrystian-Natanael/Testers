/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:19:48 by cnatanae          #+#    #+#             */
/*   Updated: 2023/11/18 13:44:21 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_gnl.h"

MU_TEST(test_gnl_passing_empy_file)
{
	int fd;
	char *expeted_result;
	char *result;
	fd = open ("includes/texts/5-empty.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file - test 1");
		exit(1);
	}
	result = get_next_line(fd);
	expeted_result = NULL;
	close(fd);
	mu_assert_string_eq(expeted_result, result);
	free(result);
}

MU_TEST(test_gnl_passing_one_char)
{
	int fd;
	char expeted_result[3] = "z\n\0";
	char *result;
	fd = open ("includes/texts/7-onechar.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file test 2");
		exit(1);
	}
	result = get_next_line(fd);
	close(fd);
	mu_assert_string_eq(expeted_result, result);
	free(result);
}

MU_TEST(test_gnl_passing_bigben)
{
	char	*expeted_result;
	char	*result;
	char	line[1024];
	int		i;
	int		fd;
	FILE	*file;

	i = 0;
	file = fopen("includes/texts/12-bigben.txt", "r");
	fd = open ("includes/texts/12-bigben.txt", O_RDONLY);
	if ( !file ||fd == -1)
	{
		perror("Error opening file test 3");
		exit(1);
	}
	while(i++ <= 70)
	{
		result = get_next_line(fd);
		expeted_result = fgets(line, sizeof(line), file);
		if (expeted_result == NULL && result == NULL)
			mu_assert_int_eq(1, 1);
		else if (expeted_result == NULL && result != NULL)
			mu_assert_int_eq(1, 2);
		else if(strcmp(expeted_result, result) != 0)
			mu_assert_int_eq(1, 2);
		free(result);
	}
	mu_assert_int_eq(1, 1);
	close(fd);
	fclose(file);
}

MU_TEST_SUITE(Get_next_line_tester)
{
	MU_RUN_TEST(test_gnl_passing_empy_file);
	MU_RUN_TEST(test_gnl_passing_one_char);
	MU_RUN_TEST(test_gnl_passing_bigben);
}

int	main(void)
{
	MU_RUN_SUITE(Get_next_line_tester);
	MU_REPORT();
	return MU_EXIT_CODE;
}