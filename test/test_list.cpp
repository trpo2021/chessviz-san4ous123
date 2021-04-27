#include <chesslib.hpp>
#include <gtest.h>

TEST(chessboard, init_desk)
{
    // Arrange
    char desk[8][8];
    const char* exp[9]
            = {"rnbqkbnr",
               "pppppppp",
               "        ",
               "        ",
               "        ",
               "        ",
               "PPPPPPPP",
               "RNBQKBNR"};

    // Act
    init_desk(desk);

    // Assert
    for (int i = 0; i < 64; i++) {
        EXPECT_EQ(desk[i / 8][i % 8], exp[i / 8][i % 8]);
    }
}

// TEST(chessboard, init_desk)
// {
//     // Arrange
//     // Act
//     // Assert
// }

// TEST(chessboard, init_desk)
// {
//     // Arrange
//     // Act
//     // Assert
// }

// TEST(chessboard, init_desk)
// {
//     // Arrange
//     // Act
//     // Assert
// }
