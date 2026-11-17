using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ToolTip;

namespace Pizza_Poject
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();

            btnOrderPizza.Select();
        }


        int sumPrice = 0;

        private void rdSmall_CheckedChanged(object sender, EventArgs e)
        {
            if (rdSmall.Checked)
            {
                lbSizeAnswer.Text = "Small";
                lbSizeAnswer.ForeColor = Color.LimeGreen;
                lbPriceAnswer.ForeColor = Color.LimeGreen;
                SumToPrice(10);
            }
            else
            {
                lbSizeAnswer.Text = "No choose.";
                lbSizeAnswer.ForeColor = Color.Red;
                SubtractedFromPrice(10);
            }
        }

        private void rdMedium_CheckedChanged(object sender, EventArgs e)
        {
            if (rdMedium.Checked)
            {
                lbSizeAnswer.Text = "Medium";
                lbSizeAnswer.ForeColor = Color.LimeGreen;
                lbPriceAnswer.ForeColor = Color.LimeGreen;
                SumToPrice(20);
            }
            else
            {
                lbSizeAnswer.Text = "No choose.";
                lbSizeAnswer.ForeColor = Color.Red;
                SubtractedFromPrice(20);
            }

        }

        private void rdLarge_CheckedChanged(object sender, EventArgs e)
        {
            if(rdLarge.Checked)
            {
                lbSizeAnswer.Text = "Large";
                lbSizeAnswer.ForeColor = Color.LimeGreen;
                lbPriceAnswer.ForeColor = Color.LimeGreen;
                SumToPrice(30);
            }
            else
            {
                lbSizeAnswer.Text = "No choose.";
                lbSizeAnswer.ForeColor = Color.Red;
                SubtractedFromPrice(30);
            }

        }

        private void chkExtraCheese_CheckedChanged(object sender, EventArgs e)
        {
            if(chkExtraCheese.Checked)
            {
                if(lbToppingsAnswer.Text == "No Toppings.")
                {
                    lbToppingsAnswer.Text = "Extra Cheese";
                    lbToppingsAnswer.ForeColor = Color.LimeGreen;
                    lbPriceAnswer.ForeColor = Color.LimeGreen;
                    SumToPrice(10);
                    UpdateLabelSize();
                }
                else
                {
                    lbToppingsAnswer.Text += ", Extra Cheese";
                    SumToPrice(10);
                    UpdateLabelSize();
                }
            }
            else
            {
                if(lbToppingsAnswer.Text == "Extra Cheese")
                {
                    lbToppingsAnswer.Text = "No Toppings.";

                    lbToppingsAnswer.ForeColor = Color.Red;
                    SubtractedFromPrice(10);
                }
                else if(lbToppingsAnswer.Text.StartsWith("Extra Cheese"))
                {
                    lbToppingsAnswer.Text = lbToppingsAnswer.Text.Remove(0, "Extra Cheese, ".Length);
                    SubtractedFromPrice(10);
                }
                else
                {
                    lbToppingsAnswer.Text = lbToppingsAnswer.Text.Remove(lbToppingsAnswer.Text.IndexOf(", Extra Cheese"), ", Extra Cheese".Length);
                    SubtractedFromPrice(10);
                }
            }
        }

        private void chkOnion_CheckedChanged(object sender, EventArgs e)
        {
            if(chkOnion.Checked)
            {
                if (lbToppingsAnswer.Text == "No Toppings.")
                {
                    lbToppingsAnswer.Text = "Onion";
                    lbToppingsAnswer.ForeColor = Color.LimeGreen;
                    lbPriceAnswer.ForeColor = Color.LimeGreen;
                    SumToPrice(10);
                    UpdateLabelSize();
                }
                else
                {
                    lbToppingsAnswer.Text += ", Onion";
                    SumToPrice(10);
                    UpdateLabelSize();
                }
                
            }
            else
            {
                if(lbToppingsAnswer.Text == "Onion")
                {
                    lbToppingsAnswer.Text = "No Toppings.";
                    lbToppingsAnswer.ForeColor = Color.Red;
                    SubtractedFromPrice(10);
                }
                else if (lbToppingsAnswer.Text.StartsWith("Onion"))
                {
                    lbToppingsAnswer.Text = lbToppingsAnswer.Text.Remove(0, "Onion, ".Length);
                    SubtractedFromPrice(10);
                }
                else
                {
                    lbToppingsAnswer.Text = lbToppingsAnswer.Text.Remove(lbToppingsAnswer.Text.IndexOf(", Onion"), ", Onion".Length);
                    SubtractedFromPrice(10);
                }
            }
        }

        private void chkMushrooms_CheckedChanged(object sender, EventArgs e)
        {
            if(chkMushrooms.Checked)
            {
                if(lbToppingsAnswer.Text == "No Toppings.")
                {
                    lbToppingsAnswer.Text = "Mushrooms";
                    lbToppingsAnswer.ForeColor = Color.LimeGreen;
                    lbPriceAnswer.ForeColor = Color.LimeGreen;
                    SumToPrice(10);
                    UpdateLabelSize();
                }
                else
                {
                    lbToppingsAnswer.Text += ", Mushrooms";
                    SumToPrice(10);
                    UpdateLabelSize();
                }
            }
            else
            {
                if(lbToppingsAnswer.Text == "Mushrooms")
                {
                    lbToppingsAnswer.Text = "No Toppings.";
                    lbToppingsAnswer.ForeColor = Color.Red;
                    SubtractedFromPrice(10);
                }
                else if (lbToppingsAnswer.Text.StartsWith("Mushrooms"))
                {
                    lbToppingsAnswer.Text = lbToppingsAnswer.Text.Remove(0, "Mushrooms, ".Length);
                    SubtractedFromPrice(10);
                }
                else
                {
                    lbToppingsAnswer.Text = lbToppingsAnswer.Text.Remove(lbToppingsAnswer.Text.IndexOf(", Mushrooms"), ", Mushrooms".Length);
                    SubtractedFromPrice(10);
                }
            }
        }

        private void chkOlives_CheckedChanged(object sender, EventArgs e)
        {
            if(chkOlives.Checked)
            {
                if(lbToppingsAnswer.Text == "No Toppings.")
                {
                    lbToppingsAnswer.Text = "Olives";
                    lbToppingsAnswer.ForeColor = Color.LimeGreen;
                    lbPriceAnswer.ForeColor = Color.LimeGreen;
                    SumToPrice(10);
                    UpdateLabelSize();
                }
                else
                {
                    lbToppingsAnswer.Text += ", Olives";
                    SumToPrice(10);
                    UpdateLabelSize();
                }
            }
            else
            {
                if(lbToppingsAnswer.Text == "Olives")
                {
                    lbToppingsAnswer.Text = "No Toppings.";
                    lbToppingsAnswer.ForeColor = Color.Red;
                    SubtractedFromPrice(10);
                }
                else if (lbToppingsAnswer.Text.StartsWith("Olives"))
                {
                    lbToppingsAnswer.Text = lbToppingsAnswer.Text.Remove(0, "Olives, ".Length);
                    SubtractedFromPrice(10);
                }
                else
                {
                    lbToppingsAnswer.Text = lbToppingsAnswer.Text.Remove(lbToppingsAnswer.Text.IndexOf(", Olives"), ", Olives".Length);
                    SubtractedFromPrice(10);
                }
            }
        }

        private void chkTomatoes_CheckedChanged(object sender, EventArgs e)
        {
            if(chkTomatoes.Checked)
            {
                if(lbToppingsAnswer.Text == "No Toppings.")
                {
                    lbToppingsAnswer.Text = "Tomatoes";
                    lbToppingsAnswer.ForeColor = Color.LimeGreen;
                    lbPriceAnswer.ForeColor = Color.LimeGreen;
                    SumToPrice(10);
                    UpdateLabelSize();
                }
                else
                {
                    lbToppingsAnswer.Text += ", Tomatoes";
                    SumToPrice(10);
                    UpdateLabelSize();
                }
            }
            else
            {
                if (lbToppingsAnswer.Text == "Tomatoes")
                {
                    lbToppingsAnswer.Text = "No Toppings.";
                    lbToppingsAnswer.ForeColor = Color.Red;
                    SubtractedFromPrice(10);
                }
                else if (lbToppingsAnswer.Text.StartsWith("Tomatoes"))
                {
                    lbToppingsAnswer.Text = lbToppingsAnswer.Text.Remove(0, "Tomatoes, ".Length);
                    SubtractedFromPrice(10);
                }
                else
                {
                    lbToppingsAnswer.Text = lbToppingsAnswer.Text.Remove(lbToppingsAnswer.Text.IndexOf(", Tomatoes"), ", Tomatoes".Length);
                    SubtractedFromPrice(10);
                }
            }
        }

        private void chkGreenPeppers_CheckedChanged(object sender, EventArgs e)
        {
            if(chkGreenPeppers.Checked)
            {
                if (lbToppingsAnswer.Text == "No Toppings.")
                {
                    lbToppingsAnswer.Text = "Green Pepperse";
                    lbToppingsAnswer.ForeColor = Color.LimeGreen;
                    lbPriceAnswer.ForeColor = Color.LimeGreen;
                    SumToPrice(10);
                    UpdateLabelSize();
                }
                else
                {
                    lbToppingsAnswer.Text += ", Green Pepperse";
                    SumToPrice(10);
                    UpdateLabelSize();
                }
            }
            else
            {
                if (lbToppingsAnswer.Text == "Green Pepperse")
                {
                    lbToppingsAnswer.Text = "No Toppings.";
                    lbToppingsAnswer.ForeColor = Color.Red;
                    SubtractedFromPrice(10);
                }
                else if (lbToppingsAnswer.Text.StartsWith("Green Pepperse"))
                {
                    lbToppingsAnswer.Text = lbToppingsAnswer.Text.Remove(0, "Green Pepperse, ".Length);
                    SubtractedFromPrice(10);
                }
                else
                {
                    lbToppingsAnswer.Text = lbToppingsAnswer.Text.Remove(lbToppingsAnswer.Text.IndexOf(", Green Pepperse"), ", Green Pepperse".Length);
                    SubtractedFromPrice(10);
                }
            }
        }

        private void rdThinCrust_CheckedChanged(object sender, EventArgs e)
        {
            if (rdThinCrust.Checked)
            {
                lbCrustTybeAnswer.Text = "Thin Crust";
                lbCrustTybeAnswer.ForeColor = Color.LimeGreen;
                lbPriceAnswer.ForeColor = Color.LimeGreen;
                SumToPrice(10);
            }
            else
            {
                lbCrustTybeAnswer.Text = "No choose";
                lbCrustTybeAnswer.ForeColor = Color.Red;
                SubtractedFromPrice(10);
            }

        }

        private void rdThickCrust_CheckedChanged(object sender, EventArgs e)
        {
            if (rdThickCrust.Checked)
            {
                lbCrustTybeAnswer.Text = "Thick Crust";
                lbCrustTybeAnswer.ForeColor = Color.LimeGreen;
                lbPriceAnswer.ForeColor = Color.LimeGreen;
                SumToPrice(10);
            }
            else
            {
                lbCrustTybeAnswer.Text = "No choose";
                lbCrustTybeAnswer.ForeColor = Color.Red;
                SubtractedFromPrice(10);
            }

        }

        private void rdEatIn_CheckedChanged(object sender, EventArgs e)
        {
            if (rdEatIn.Checked)
            {
                lbWhereToEatAnswer.Text = "Eat In";
                lbWhereToEatAnswer.ForeColor = Color.LimeGreen;
            }
            else
            {
                lbWhereToEatAnswer.Text = "No choose.";
                lbWhereToEatAnswer.ForeColor = Color.Red;
            }
            
        }

        private void rdTakeOut_CheckedChanged(object sender, EventArgs e)
        {
            if (rdTakeOut.Checked)
            {
                lbWhereToEatAnswer.Text = "Take Out";
                lbWhereToEatAnswer.ForeColor = Color.LimeGreen;
            }
            else
            {
                lbWhereToEatAnswer.Text = "No choose.";
                lbWhereToEatAnswer.ForeColor = Color.Red;
            }

        }

        private void UpdateLabelSize()
        {
            lbToppingsAnswer.AutoSize = true;

            lbToppingsAnswer.MaximumSize = new Size(gbOrderSize.ClientSize.Width - lbToppingsAnswer.Left - 10, 0);
        }

        private void SumToPrice(int Price)
        {

            sumPrice += Price;
            lbPriceAnswer.Text = sumPrice.ToString() + "$";
        }

        private void SubtractedFromPrice(int Price)
        {
            sumPrice -= Price;
            lbPriceAnswer.Text = sumPrice.ToString() + "$";
        }

        private void btnOrderPizza_MouseEnter(object sender, EventArgs e)
        {
            btnOrderPizza.BackColor = Color.FromArgb(46, 125, 50);
        }

        private void btnOrderPizza_MouseLeave(object sender, EventArgs e)
        {
            btnOrderPizza.BackColor = Color.FromArgb(56, 142, 60);

        }

        private void btnResetForm_MouseLeave(object sender, EventArgs e)
        {
            btnResetForm.BackColor = Color.FromArgb(183, 28, 28);
        }

        private void btnResetForm_MouseEnter(object sender, EventArgs e)
        {
            btnResetForm.BackColor = Color.FromArgb(198, 40, 40);
        }

        private void btnOrderPizza_Click(object sender, EventArgs e)
        {
            if (lbPriceAnswer.Text == "0$")
            {
                MessageBox.Show("Please Select Pizza Size", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            if (MessageBox.Show("Confirm Order", "Confirm", MessageBoxButtons.OKCancel, MessageBoxIcon.Information) == DialogResult.OK)
            {

                MessageBox.Show("Order Placed Succesfully", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);


                gbSize.Enabled = false;
                gbToppings.Enabled = false;
                gbCrustTybe.Enabled = false;
                gbWhereToEat.Enabled = false;
                btnOrderPizza.Enabled = false;
                
            }
            
        }

        void ResetForm()
        {
            
            //Reset all checkboxes and ridio button
            rdSmall.Checked = false;
            rdMedium.Checked = false;
            rdLarge.Checked = false;

            rdThinCrust.Checked = false;
            rdThickCrust.Checked = false;

            rdEatIn.Checked = false;
            rdTakeOut.Checked = false;

            chkExtraCheese.Checked = false;
            chkMushrooms.Checked = false;
            chkOlives.Checked = false;
            chkOnion.Checked = false;
            chkTomatoes.Checked = false;
            chkGreenPeppers.Checked = false;

            //Reset Order Summary Label
            lbPriceAnswer.ForeColor = Color.Red;


            //Enaple all group boxes and buttons
            gbSize.Enabled = true;
            gbToppings.Enabled = true;
            gbCrustTybe.Enabled = true;
            gbWhereToEat.Enabled = true;
            btnOrderPizza.Enabled = true;
        }

        private void btnResetForm_Click(object sender, EventArgs e)
        {
            ResetForm();
        }

        
    }
}
