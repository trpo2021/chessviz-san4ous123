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

TEST(step, do_step)
{
    // Arrange
    Step step;
    step = interpret_notation("e2-e4");
    char desk[8][8];
    init_desk(desk);
    // Act
    do_step(desk, step);

    // Assert
    EXPECT_EQ(desk[6][4], ' ');
    EXPECT_EQ(desk[4][4], 'P');
}

TEST(error, is_existing_range)
{
    // Arrange
    Step true_step, false_step;
    true_step = interpret_notation("e2-e9");
    false_step = interpret_notation("e2-e4");
    bool exp_true;
    bool exp_false;

    // Act
    exp_true = is_existing_range(true_step);
    exp_false = is_existing_range(false_step);

    // Assert
    EXPECT_TRUE(exp_true);
    EXPECT_FALSE(exp_false);
}

TEST(error, err_massage)
{
    // Arrange
    const string exp_1 = "unexisting range";
    const string exp_2 = "undefined error";
    string real_1;
    string real_2;
    // Act
    real_1 = err_massage(1);
    real_2 = err_massage(2);

    // Assert
    EXPECT_EQ(exp_1, real_1);
    EXPECT_EQ(exp_2, real_2);
}

TEST(error, check_step)
{
    // Arrange
    Step true_step, false_step;
    true_step = interpret_notation("e2-e4");
    false_step = interpret_notation("e2-e9");
    char desk[8][8];
    init_desk(desk);
    int err_cod_true;
    int err_cod_false;
    // Act
    err_cod_true = check_step(desk, true_step);
    err_cod_false = check_step(desk, false_step);

    // Assert
    EXPECT_EQ(err_cod_true, 0);
    EXPECT_EQ(err_cod_false, 1);
}
