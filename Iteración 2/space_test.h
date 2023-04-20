/**
 * @brief It declares the tests for the space module
 *
 * @file space_test.h
 * @author Profesores Pprog
 * @version 2.0
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
 * @test Test space creation
 * @pre Space ID
 * @post Non NULL pointer to space
 */
void test1_space_create();

/**
 * @test Test space creation
 * @pre Space ID
 * @post Space_ID == Supplied Space Id
 */
void test2_space_create();

/**
 * @test Test function for space_name setting
 * @pre String with space name
 * @post Ouput==OK
 */
void test1_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space = NULL
 * @post Output==ERROR
 */
void test2_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space_name = NULL (point to space = NON NULL)
 * @post Output==ERROR
 */
void test3_space_set_name();
/**
 * @test Test function for space_north setting
 * @pre Space ID
 * @post Output==OK
 */
void test1_space_set_north();
/**
 * @test Test function for space_north setting
 * @pre pointer to space = NULL
 * @post Output==ERROR
 */
void test2_space_set_north();
/**
 * @test Test function for space_south setting
 * @pre Space ID
 * @post Output==OK
 */
void test1_space_set_south();
/**
 * @test Test function for space_south setting
 * @pre pointer to space = NULL
 * @post Output==ERROR
 */
void test2_space_set_south();

/**
 * @test Test function for space_east setting
 * @pre Space ID
 * @post Output==OK
 */
void test1_space_set_east();
/**
 * @test Test function for space_east setting
 * @pre pointer to space = NULL
 * @post Output==ERROR
 */
void test2_space_set_east();
/**
 * @test Test function for space_west setting
 * @pre Space ID
 * @post Output==OK
 */
void test1_space_set_west();
/**
 * @test Test function for space_west setting
 * @pre pointer to space = NULL
 * @post Output==ERROR
 */
void test2_space_set_west();
/**
 * @test Test function for space_id get
 * @pre Space ID
 * @post Output == Suplied Space ID
 */
void test1_space_get_id();
/**
 * @test Test function for space_id get
 * @pre pointer to space = NULL
 * @post Output == ERROR
 */
void test2_space_get_id();

/**
 * @test Test function for space_name get
 * @pre string with the name
 * @post Output == strcmp = 0
 */
void test1_space_get_name();

/**
 * @test Test function for space_name get
 * @pre pointer to space = NULL
 * @post Output == ERROR
 */
void test2_space_get_name();
/**
 * @test Test function for space_north get
 * @pre Space ID
 * @post Output == Suplied Space ID
 */
void test1_space_get_north();
/**
 * @test Test function for space_north get
 * @pre pointer to space = NULL
 * @post Output == ERROR
 */
void test2_space_get_north();
/**
 * @test Test function for space_south get
 * @pre Space ID
 * @post Output == Suplied Space ID
 */
void test1_space_get_south();

/**
 * @test Test function for space_south get
 * @pre pointer to space = NULL
 * @post Output == ERROR
 */
void test2_space_get_south();
/**
 * @test Test function for space_east get
 * @pre Space ID
 * @post Output == Suplied Space ID
 */
void test1_space_get_east();
/**
 * @test Test function for space_east get
 * @pre pointer to space = NULL
 * @post Output == ERROR
 */
void test2_space_get_east();
/**
 * @test Test function for space_west get
 * @pre Space ID
 * @post Output == Suplied Space ID
 */
void test1_space_get_west();
/**
 * @test Test function for space_west get
 * @pre pointer to space = NULL
 * @post Output == ERROR
 */
void test2_space_get_west();
/**
 * @test Test function for object setting
 * @pre Object ID
 * @post Output == OK
 */
void test1_space_add_object();
/**
 * @test Test function for object setting
 * @pre pointer to space = NULL
 * @post Output == ERROR
 */
void test2_space_add_object();
/**
 * @test Test function for object setting
 * @pre pointer to space_name = NULL (point to space = NON NULL)
 * @post Output == ERROR
 */
void test3_space_add_object();

/**
 * @test Test function for removing object
 * @pre Object and Space ID
 * @post Output == OK
 */
void test1_space_remove_object();
/**
 * @test Test function for removing object
 * @pre try to remove non existing object
 * @post Output == ERROR
 */
void test2_space_remove_object();

/**
 * @test Test function for searching objects
 * @pre Space ID
 * @post Output == FALSE
 */
void test1_space_has_object();
/**
 * @test Test function for searching objects
 * @pre object NO_ID
 * @post Output == FALSE
 */
void test2_space_has_object();
/**
 * @test Test function for searching objects
 * @pre pointer to space = NULL
 * @post Output == FALSE
 */
void test3_space_has_object();

/**
 * @test Test function for searching objects
 * @pre searchs for added object
 * @post Output == TRUE
 */
void test4_space_has_object();
/**
 * @test Test function for getting the graphic description
 * @pre Gets the graphic description
 * @post Output != NULL
 */
void test1_space_get_gdesc();
/**
 * @test Test function for getting the graphic description
 * @pre Try to get the graphic description of a non existing space
 * @post Output == NULL
 */
void test2_space_get_gdesc();
/**
 * @test Test function for setting the graphic description
 * @pre NULL gdesc
 * @post Output == ERROR
 */
void test1_space_set_gdesc();

/**
 * @test Test function for setting the graphic description
 * @pre Try to set the graphic description of a non existing space
 * @post Output == ERROR
 */
void test2_space_set_gdesc();

/**
 * @test Test function for setting the set
 * @pre NULL set
 * @post Output == ERROR 
 * 
 */
void test1_space_set_set();

/**
 * @test Test function for setting the set
 * @pre Try to set the set of a non existing space
 * @post Output == ERROR
 * 
 */
void test2_space_set_set();

/**
 * @test Test function for getting the set
 * @pre Gets the set
 * @post Output != NULL
 */
void test1_space_get_set();
/**
 * @test Test function for getting the set
 * @pre Try to get the set of a non existing space
 * @post Output == NULL
 */
void test2_space_get_set();

/**
 * @test Test function for getting the number of objects
 * @pre Gets the number of objects
 * @post Output == 0
 */
void test1_space_get_nObjects();
/**
 * @test Test function for getting the number of objects
 * @pre Try to get the number of objects of a non existing space
 * @post Output == NULL
 */
void test2_space_get_nObjects();

#endif
