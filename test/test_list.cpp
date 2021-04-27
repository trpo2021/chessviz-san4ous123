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

TEST(step, interpret_notation)
{
    // Arrange
    Step step_st;
    Step step_pawn;
    const string notation_st = "Bf1-c4";
    const string notation_pawn = "b2-c4";
    Step exp_st;
    Step exp_pawn;

    exp_st.piece = 'B';
    exp_st.first_node = DeskCoord(7, 5);
    exp_st.second_node = DeskCoord(4, 2);

    exp_pawn.piece = 'P';
    exp_pawn.first_node = DeskCoord(6, 1);
    exp_pawn.second_node = DeskCoord(4, 2);

    // Act
    step_st = interpret_notation(notation_st);
    step_pawn = interpret_notation(notation_pawn);

    // Assert
    EXPECT_EQ(step_st.first_node, exp_st.first_node);
    EXPECT_EQ(step_st.second_node, exp_st.second_node);
    EXPECT_EQ(step_st.piece, exp_st.piece);

    EXPECT_EQ(step_pawn.first_node, exp_pawn.first_node);
    EXPECT_EQ(step_pawn.second_node, exp_pawn.second_node);
    EXPECT_EQ(step_pawn.piece, exp_pawn.piece);
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
