// library includes
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Reverse a string in place.
*/
void Reverse(char* string, uint16_t start, uint16_t end)
{
    if (!string)
    {
        return;
    }

    while (start < end)
    {
        char swap = *(string + start);
        *(string + start) = *(string + end);
        *(string + end) = swap;
        ++start;
        --end;
    }
}

void ReverseString(char* string)
{
    if (!string)
    {
        return;
    }

    uint16_t back = 0;
    while (*(string + back) != '\0')
    {
        ++back;
    }

    --back;
    Reverse(string, 0, back);
}

void TestReverseString()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    char string[7] = { '1', '3', '0', '0', 'c', 'c', '\0' };
    printf("String:%s\n", string);

    ReverseString(string);

    printf("Reversed string:%s\n", string);

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

/*
Reverse the words in a string in place.
*/
void ReverseWords(char* sentence)
{
    if (!sentence)
    {
        return;
    }

    uint16_t i = 0, start = 0;
    while (*(sentence + i) != '\0')
    {
        if (*(sentence + i) == ' ')
        {
            Reverse(sentence, start, i - 1);
            start = i + 1;
        }
        ++i;
    }

    Reverse(sentence, start, i - 1);
}

void TestReverseWords()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    char sentence[26] = { 'm', 'a', 'y', ' ', 't', 'h', 'e', ' ', 'f', 'o', 'r', 'c', 'e', ' ', 'b', 'e', ' ', 'w', 'i', 't', 'h', ' ', 'y', 'o', 'u', '\0' };
    printf("Sentence:%s\n", sentence);

    ReverseWords(sentence);

    printf("Reversed sentence:%s\n", sentence);

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

/*
Implement the CRT strlen() : size_t strlen(const char* i_str)
*/
size_t StringLength(const char* i_str)
{
    assert(i_str);

    size_t length = 0;
    while (*(i_str + length) != '\0')
    {
        ++length;
    }

    return length;
}

void TestStringLength()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    const char* str = "1300cc";
    printf("StringLength(%s) = %zu\n", str, StringLength(str));

    str = "";
    printf("StringLength(%s) = %zu\n", str, StringLength(str));

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

/*
Implement the CRT strcmp() : int strcmp( const char * i_lhs, const char * i_rsh).
*/
int StringCompare(const char* i_lhs, const char* i_rhs)
{
    assert(i_lhs && i_rhs);

    size_t i = 0;
    while (1)
    {
        if (*(i_lhs + i) == *(i_rhs + i))
        {
            if (*(i_lhs + i) == '\0')
            {
                return 0;
            }
            ++i;
            continue;
        }

        return *(i_lhs + i) > *(i_rhs + i) ? 1 : -1;
    }

    return 0;
}

void TestStringCompare()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    const char* s1 = "aaa";
    const char* s2 = "aaa";
    printf("StringCompare(%s, %s) = %d\n", s1, s2, StringCompare(s1, s2));

    s1 = "aaa";
    s2 = "aac";
    printf("StringCompare(%s, %s) = %d\n", s1, s2, StringCompare(s1, s2));

    s1 = "aas";
    s2 = "aaa";
    printf("StringCompare(%s, %s) = %d\n", s1, s2, StringCompare(s1, s2));

    s1 = "ad";
    s2 = "aaa";
    printf("StringCompare(%s, %s) = %d\n", s1, s2, StringCompare(s1, s2));

    s1 = "aa";
    s2 = "aad";
    printf("StringCompare(%s, %s) = %d\n", s1, s2, StringCompare(s1, s2));

    s1 = "aag";
    s2 = "aa";
    printf("StringCompare(%s, %s) = %d\n", s1, s2, StringCompare(s1, s2));

    s1 = "aag";
    s2 = "ad";
    printf("StringCompare(%s, %s) = %d\n", s1, s2, StringCompare(s1, s2));

    char buf1[] = {'a', 'b', 'c'};
    char buf2[] = {'a', 'b'};
    printf("StringCompare(%s, %s) = %d\n", buf1, buf2, StringCompare(buf1, buf2));

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

/*
Implement the CRT strncmp() : int strcmp(const char* i_lhs, const char* i_rhs, const size_t i_count)
*/
int StringNCompare(const char* i_lhs, const char* i_rhs, const size_t i_count)
{
    assert(i_lhs && i_rhs && i_count);

    size_t i = 0;
    while (i < i_count)
    {
        if (*(i_lhs + i) == *(i_rhs + i))
        {
            if (*(i_lhs + i) == '\0')
            {
                return 0;
            }
            ++i;
            continue;
        }

        return *(i_lhs + i) > *(i_rhs + i) ? 1 : -1;
    }

    return 0;
}

void TestStringNCompare()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    const char* s1 = "aaa";
    const char* s2 = "aaa";
    size_t count = 3;
    printf("StringCompare(%s, %s, %zu) = %d\n", s1, s2, count, StringNCompare(s1, s2, count));

    s1 = "aaa";
    s2 = "aac";
    count = 2;
    printf("StringCompare(%s, %s, %zu) = %d\n", s1, s2, count, StringNCompare(s1, s2, count));

    s1 = "aas";
    s2 = "aaa";
    count = 3;
    printf("StringCompare(%s, %s, %zu) = %d\n", s1, s2, count, StringNCompare(s1, s2, count));

    s1 = "ad";
    s2 = "aaa";
    count = 3;
    printf("StringCompare(%s, %s, %zu) = %d\n", s1, s2, count, StringNCompare(s1, s2, count));

    s1 = "aa";
    s2 = "aad";
    count = 2;
    printf("StringCompare(%s, %s, %zu) = %d\n", s1, s2, count, StringNCompare(s1, s2, count));

    s1 = "aag";
    s2 = "aa";
    count = 2;
    printf("StringCompare(%s, %s, %zu) = %d\n", s1, s2, count, StringNCompare(s1, s2, count));

    s1 = "aag";
    s2 = "ad";
    count = 1;
    printf("StringCompare(%s, %s, %zu) = %d\n", s1, s2, count, StringNCompare(s1, s2, count));

    char buf1[] = {'a', 'b', 'c'};
    char buf2[] = {'a', 'b'};
    count = 4;
    printf("StringCompare(%s, %s, %zu) = %d\n", buf1, buf2, count, StringNCompare(buf1, buf2, count));

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

/*
Implement the CRT strstr() : char* strstr(const char* str, const char* substr)
*/
char* StrStr(const char* str, const char* substr)
{
    assert(str && substr);

    char* start = nullptr;
    size_t i = 0;
    while (*(str + i) != '\0')
    {
        if (*(str + i) == *(substr))
        {
            start = const_cast<char*>(str + i);

            ++i;
            size_t j = 1;
            while (1)
            {
                if (*(str + i) == *(substr + j))
                {
                    if (*(str + i) == '\0')
                    {
                        return start;
                    }

                    ++i;
                    ++j;
                    continue;
                }

                if (*(str + i) == '\0')
                {
                    return nullptr;
                }
                else if (*(substr + j) == '\0')
                {
                    return start;
                }
                else
                {
                    start = nullptr;
                    break;
                }
            }
        }
        else
        {
            ++i;
        }
    }

    return nullptr;
}

void TestStrStr()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    const char* str = "1300cc";
    const char* substr = "1";
    char* start = StrStr(str, substr);
    printf("StrStr(%s, %s) = %s\n", str, substr, start ? start : "nullptr");

    str = "1300cc";
    substr = "k";
    start = StrStr(str, substr);
    printf("StrStr(%s, %s) = %s\n", str, substr, start ? start : "nullptr");

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

/*
Remove a given character from a string in place ( "AABBAABBC" - 'A' becomes "BBBBC").
*/
void RemoveCharFromString(const char c, char* s)
{
    assert(s);

    uint16_t i = 0;
    while (*(s + i) != '\0')
    {
        if (*(s + i) == c)
        {
            uint16_t j = i + 1;
            while (*(s + j) != '\0')
            {
                *(s + j - 1) = *(s + j);
                ++j;
            }
            *(s + j - 1) = '\0';
        }
        else
        {
            ++i;
        }
    }
}

void TestRemoveCharFromString()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    char string[7] = { '1', '3', '0', '0', 'c', 'c', '\0' };
    const char remove = '0';

    printf("String before removing %c:%s\n", remove, string);

    RemoveCharFromString(remove, string);

    printf("String after removing %c:%s\n", remove, string);

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

/*
Remove side-by-side duplicate characters in a string ("AAA BBB" becomes "A B") in place.
*/
void RemoveAdjacentDuplicatesFromString(char* s)
{
    assert(s);

    uint16_t i = 0;
    while (*(s + i) != '\0' && *(s + i + 1) != '\0')
    {
        if (*(s + i) == *(s + i + 1))
        {
            uint16_t j = i + 1;
            while (*(s + j) != '\0')
            {
                *(s + j - 1) = *(s + j);
                ++j;
            }
            *(s + j - 1) = '\0';
        }
        else
        {
            ++i;
        }
    }
}

void TestRemoveAdjacentDuplicatesFromString()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    char string[7] = { '1', '1', '0', '0', 'c', 'c', '\0' };

    printf("String before removing adjacent duplicates:%s\n", string);

    RemoveAdjacentDuplicatesFromString(string);

    printf("String after removing adjacent duplicates:%s\n", string);

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

/*
Split a sentence, given as const char *, into the individual words. Return an array of char *'s containing the words.
*/
char** SplitSentenceIntoWords(const char* i_sentence, uint16_t& o_num_words)
{
    assert(i_sentence);

    // calculate the number of words
    uint16_t num_words = 0;
    uint16_t i = 0;

    while (*(i_sentence + i) != '\0')
    {
        num_words += (*(i_sentence + i) == ' ') ? 1 : 0;
        ++i;
    }
    ++num_words;

    // reserve memory for words
    char** result = (char**)(malloc(num_words * sizeof(char*)));

    i = 0;
    uint16_t word_index = 0;
    while (*(i_sentence + i) != '\0')
    {
        // calculate number of characters in this word
        uint16_t word_len = 0;
        while (*(i_sentence + i + word_len) != '\0' && *(i_sentence + i + word_len) != ' ')
        {
            ++word_len;
        }
        // reserve memory for the characters in this word
        *(result + word_index) = (char*)(malloc(word_len + 1));

        // copy the characters from the sentence into this word
        uint16_t j = 0;
        while (j < word_len)
        {
            *(*(result + word_index) + j) = *(i_sentence + i + j);
            ++j;
        }
        // add null termination
        *(*(result + word_index) + j) = '\0';

        // move to the next word
        i += word_len + 1;
        ++word_index;
    }

    o_num_words = num_words;
    return result;
}

void TestSplitSentenceIntoWords()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    const char* sentence = "i am a bot";
    uint16_t num_words;

    printf("Sentence to split:%s\n", sentence);

    char** words = SplitSentenceIntoWords(sentence, num_words);

    printf("%d-words:\n", num_words);
    uint16_t i = 0;
    while (i < num_words)
    {
        printf("%s\n", *(words + i));
        free(*(words + i));
        ++i;
    }
    free(words);

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

