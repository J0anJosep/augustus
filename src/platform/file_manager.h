#ifndef PLATFORM_FILE_MANAGER_H
#define PLATFORM_FILE_MANAGER_H

#include <stdio.h>

enum {
    TYPE_NONE = 0,
    TYPE_DIR = 1,
    TYPE_FILE = 2,
    TYPE_ANY = 3
};

enum {
    LIST_ERROR = 0,
    LIST_NO_MATCH = 1,
    LIST_CONTINUE = 1,
    LIST_MATCH = 2
};

/**
 * Sets the base path for Julius
 * @param path The path to be set as the base
 * @return true if the base path was correctly set, false otherwise
 */
int platform_file_manager_set_base_path(const char *path);

/**
 * Gets the contents of a directory by the specified extension
 * @param dir The directory to search on, or null if base directory
 * @param type The file type to filter (dir, file or both)
 * @param extension The extension to filter
 * @param callback The function to call when a matched file is found
 * @return LIST_ERROR if error, LIST_MATCH if there was a match in the callback, LIST_NO_MATCH if no match was set
 */
int platform_file_manager_list_directory_contents(
    const char *dir, int type, const char *extension, int (*callback)(const char *, long));

/**
 * Indicates whether the file name casing should be checked
 * @return Whether file name casing should be checked
 */
int platform_file_manager_should_case_correct_file(void);

/**
 * Compares two filenames in a case-insensitive manner
 * @param a Filename A
 * @param b Filename B
 * @return Negative if A < B, positive if A > B, zero if A == B
 */
int platform_file_manager_compare_filename(const char *a, const char *b);

/**
 * Checks if the filename starts with the given prefix in a case-insensitive manner
 * @param filename Filename to check
 * @param prefix Prefix to check for
 * @param prefix_len Length of the prefix
 * @return Negative if filename < prefix, 0 if filename starts with prefix, positive if filename > prefix
 */
int platform_file_manager_compare_filename_prefix(const char *filename, const char *prefix, int prefix_len);

/**
 * Opens a file
 * @param filename The file to open
 * @param mode The mode to open the file - refer to fopen()
 * @return A pointer to a FILE structure on success, NULL otherwise
 */
FILE *platform_file_manager_open_file(const char *filename, const char *mode);

/**
 * Opens an asset file
 * @param filename The asset file to open
 * @param mode The mode to open the asset file - refer to fopen()
 * @return A pointer to a FILE structure on success, NULL otherwise
 */
FILE *platform_file_manager_open_asset(const char *asset, const char *mode);


/**
 * Closes a file
 * @param stream A pointer to the FILE structure to close
 * @return 1 if the file was closed, 0 otherwise
 */
int platform_file_manager_close_file(FILE *stream);


/**
 * Removes a file
 * @param filename The file to remove
 * @return 1 if removal was successful, 0 otherwise
 */
int platform_file_manager_remove_file(const char *filename);

/**
 * Creates a directory
 * @param path The full path to the new directory
 * @return 1 if creation was successful, false otherwise
 */
int platform_file_manager_create_directory(const char *name);

#endif // PLATFORM_FILE_MANAGER_H
