
using System;
using System.Drawing;
using System.Windows.Forms;

namespace Tic_Tac_Toe_Game_Project
{
    public partial class frmTic : Form
    {
        public frmTic()
        {
            InitializeComponent();
        }

        enum enPlayer
        {
            Player1,
            Player2
        }

        enum enWinner
        {
            Player1,
            Player2,
            Draw,
            GameInProgress
        }

        struct stGameStatus
        {
            public enWinner Winner;
            public bool GameOver ;
            public short PlayCount;
        }

        enPlayer PlayerTurn = enPlayer.Player1;
        stGameStatus GameStatus;

        private void frmTic_Paint(object sender, PaintEventArgs e)
        {
            Pen whitePen = new Pen(Color.White, 10);

            whitePen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            whitePen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

            e.Graphics.DrawLine(whitePen, 400, 125, 400, 425);
            e.Graphics.DrawLine(whitePen, 550, 125, 550, 425);

            e.Graphics.DrawLine(whitePen, 290, 215, 670, 215);
            e.Graphics.DrawLine(whitePen, 290, 325, 670, 325);
        }

        private bool CheckValues(Button btn1, Button btn2, Button btn3)
        {
            if (btn1.Tag.ToString() != "?" &&
                btn1.Tag.ToString() == btn2.Tag.ToString() &&
                btn2.Tag.ToString() == btn3.Tag.ToString())
            {
                btn1.BackColor = Color.Yellow;
                btn2.BackColor = Color.Yellow;
                btn3.BackColor = Color.Yellow;

                if (btn1.Tag.ToString() == "X")
                {
                    GameStatus.Winner = enWinner.Player1;
                }
                else
                {
                    GameStatus.Winner = enWinner.Player2;
                }

                GameStatus.GameOver = true;

                EndGame();

                return true;
            }

            return false;
        }

        private void CheckWinner()
        {
            // Rows
            if (CheckValues(btnGame1, btnGame2, btnGame3))
                return;

            if (CheckValues(btnGame4, btnGame5, btnGame6))
                return;

            if (CheckValues(btnGame7, btnGame8, btnGame9))
                return;

            // Columns
            if (CheckValues(btnGame1, btnGame4, btnGame7))
                return;

            if (CheckValues(btnGame2, btnGame5, btnGame8))
                return;

            if (CheckValues(btnGame3, btnGame6, btnGame9))
                return;

            // Diagonals
            if (CheckValues(btnGame1, btnGame5, btnGame9))
                return;

            if (CheckValues(btnGame3, btnGame5, btnGame7))
                return;
        }

        private void EndGame()
        {
            switch (GameStatus.Winner)
            {
                case enWinner.Player1:
                    lbwinerAnswer.Text = "Player 1";

                    MessageBox.Show("Player 1 is the winner", "Game Over",
                        MessageBoxButtons.OK, MessageBoxIcon.Information);
                    break;

                case enWinner.Player2:
                    lbwinerAnswer.Text = "Player 2";

                    MessageBox.Show("Player 2 is the winner", "Game Over",
                        MessageBoxButtons.OK, MessageBoxIcon.Information);
                    break;

                case enWinner.Draw:
                    lbwinerAnswer.Text = "Draw";

                    MessageBox.Show("Game is Draw!", "Game Over",
                        MessageBoxButtons.OK, MessageBoxIcon.Information);
                    break;
            }

            DisableAllGameButton();
        }

        private void ChangeImage(Button btn)
        {
            if (GameStatus.GameOver || btn.Tag.ToString() != "?")
                return;

            if (PlayerTurn == enPlayer.Player1)
            {
                btn.BackgroundImage = Properties.Resources.X;
                btn.Tag = "X";
            }
            else
            {
                btn.BackgroundImage = Properties.Resources.O;
                btn.Tag = "O";
            }

            btn.Enabled = false;

            GameStatus.PlayCount++;

            CheckWinner();

            if (GameStatus.GameOver)
                return;

            if (GameStatus.PlayCount == 9)
            {
                GameStatus.Winner = enWinner.Draw;
                GameStatus.GameOver = true;

                EndGame();
                return;
            }

            if (PlayerTurn == enPlayer.Player1)
            {
                PlayerTurn = enPlayer.Player2;
                lbPlayer.Text = "Player 2";
            }
            else
            {
                PlayerTurn = enPlayer.Player1;
                lbPlayer.Text = "Player 1";
            }
        }

        private void DisableAllGameButton()
        {
            btnGame1.Enabled = false;
            btnGame2.Enabled = false;
            btnGame3.Enabled = false;
            btnGame4.Enabled = false;
            btnGame5.Enabled = false;
            btnGame6.Enabled = false;
            btnGame7.Enabled = false;
            btnGame8.Enabled = false;
            btnGame9.Enabled = false;
        }

        private void ResetButton(Button btn)
        {
            btn.Enabled = true;
            btn.BackgroundImage = Properties.Resources.question_mark_96;
            btn.BackColor = Color.Transparent;
            btn.Tag = "?";
        }

        private void RestartGame()
        {
            ResetButton(btnGame1);
            ResetButton(btnGame2);
            ResetButton(btnGame3);
            ResetButton(btnGame4);
            ResetButton(btnGame5);
            ResetButton(btnGame6);
            ResetButton(btnGame7);
            ResetButton(btnGame8);
            ResetButton(btnGame9);

            PlayerTurn = enPlayer.Player1;

            GameStatus.Winner = enWinner.GameInProgress;
            GameStatus.GameOver = false;
            GameStatus.PlayCount = 0;

            lbPlayer.Text = "Player 1";
            lbwinerAnswer.Text = "In Progress";
        }

        private void frmTic_Load(object sender, EventArgs e)
        {
            RestartGame();
        }

        private void btnGame1_Click(object sender, EventArgs e)
        {
            ChangeImage((Button)sender);
        }

        private void btnGame2_Click(object sender, EventArgs e)
        {
            ChangeImage((Button)sender);
        }

        private void btnGame3_Click(object sender, EventArgs e)
        {
            ChangeImage((Button)sender);
        }

        private void btnGame4_Click(object sender, EventArgs e)
        {
            ChangeImage((Button)sender);
        }

        private void btnGame5_Click(object sender, EventArgs e)
        {
            ChangeImage((Button)sender);
        }

        private void btnGame6_Click(object sender, EventArgs e)
        {
            ChangeImage((Button)sender);
        }

        private void btnGame7_Click(object sender, EventArgs e)
        {
            ChangeImage((Button)sender);
        }

        private void btnGame8_Click(object sender, EventArgs e)
        {
            ChangeImage((Button)sender);
        }

        private void btnGame9_Click(object sender, EventArgs e)
        {
            ChangeImage((Button)sender);
        }

        private void btnRestartGame_Click(object sender, EventArgs e)
        {
            RestartGame();
        }
    }
}
