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

        private float GetSelectedSizePrice()
        {
            float SizePrice = 0;

            if (rbSmall.Checked)
            {
                SizePrice += Convert.ToSingle(rbSmall.Tag);
            }
            if (rbMedium.Checked)
            {
                SizePrice += Convert.ToSingle(rbMedium.Tag);
            }
            if (rbLarge.Checked)
            {
                SizePrice += Convert.ToSingle(rbLarge.Tag);
            }
           

            return SizePrice;
        }

        private float CalculateToppingsPrice()
        {
            float ToppingsPrice = 0;

            if (chkExtraCheese.Checked)
            {
                ToppingsPrice += Convert.ToSingle(chkExtraCheese.Tag);
            }
            if (chkOnion.Checked)
            {
                ToppingsPrice += Convert.ToSingle(chkOnion.Tag);
            }
            if (chkMushrooms.Checked)
            {
                ToppingsPrice += Convert.ToSingle(chkMushrooms.Tag);
            }
            if (chkOlives.Checked)
            {
                ToppingsPrice += Convert.ToSingle(chkOlives.Tag);
            }
            if (chkTomatoes.Checked)
            {
                ToppingsPrice += Convert.ToSingle(chkTomatoes.Tag);
            }
            if (chkGreenPeppers.Checked)
            {
                ToppingsPrice += Convert.ToSingle(chkGreenPeppers.Tag);
            }
            

            return ToppingsPrice;
        }

        private float GetSelectedCrustPrice()
        {
            float CrustPrice = 0;
            if (rbThinCrust.Checked)
            {
                CrustPrice += Convert.ToSingle(rbThinCrust.Tag);
            }
            if (rbThickCrust.Checked)
            {
                CrustPrice += Convert.ToSingle(rbThickCrust.Tag);
            }
           

            return CrustPrice;
        }

        private void CalculateTotalPrice()
        {
            lbPriceAnswer.Text = (GetSelectedSizePrice() + CalculateToppingsPrice() + GetSelectedCrustPrice()).ToString() + "$";
        }


        private void UpdateSize()
        {
            if (rbSmall.Checked)
            {
                lbSizeAnswer.Text = "Small";
                lbSizeAnswer.ForeColor = Color.LimeGreen;
            }
            if (rbMedium.Checked)
            {
                lbSizeAnswer.Text = "Medium";
                lbSizeAnswer.ForeColor = Color.LimeGreen;
            }
            if (rbLarge.Checked)
            {
                lbSizeAnswer.Text = "Large";
                lbSizeAnswer.ForeColor = Color.LimeGreen;
            }

            UpdateOrderSummary();
            CalculateTotalPrice();
        }

        private void UpdateCrustType()
        {
            if (rbThinCrust.Checked)
            {
                lbCrustTybeAnswer.Text = "Thin Crust";
                lbCrustTybeAnswer.ForeColor = Color.LimeGreen;
            }
            if (rbThickCrust.Checked)
            {
                lbCrustTybeAnswer.Text = "Thick Crust";
                lbCrustTybeAnswer.ForeColor = Color.LimeGreen;
            }

            UpdateOrderSummary();
            CalculateTotalPrice();
        }

        private void UpdateWhereToEat()
        {
            if (rbEatIn.Checked)
            {
                lbWhereToEatAnswer.Text = "Eat In";
                lbWhereToEatAnswer.ForeColor = Color.LimeGreen;

            }
            if (rbTakeOut.Checked)
            {
                lbWhereToEatAnswer.Text = "Take Out";
                lbWhereToEatAnswer.ForeColor = Color.LimeGreen;
            }

            UpdateOrderSummary();
            CalculateTotalPrice();
        }

        private void UpdateToppings()
        {
            List<string> toppings = new List<string>();


            if (chkExtraCheese.Checked)
            {
                toppings.Add("Extra Cheese");
            }
            if (chkOnion.Checked)
            {
                toppings.Add("Onion");
            }
            if (chkMushrooms.Checked)
            {
                toppings.Add("Mushrooms");
            }
            if (chkOlives.Checked)
            {
                toppings.Add("Olives");
            }
            if (chkTomatoes.Checked)
            {
                toppings.Add("Tomatoes");
            }
            if (chkGreenPeppers.Checked)
            {
                toppings.Add("Green Peppers");
            }


            if(toppings.Count > 0)
            {
                lbToppingsAnswer.Text = string.Join(", ", toppings);
                //CalculateTotalPrice(); Error
                lbToppingsAnswer.ForeColor = Color.LimeGreen;
            }
            else
            {
                lbToppingsAnswer.Text = "No Toppings.";

                lbToppingsAnswer.ForeColor = Color.Red;

            }

            UpdateOrderSummary();
            CalculateTotalPrice();

        }
        

        private void rdSmall_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rdMedium_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rdLarge_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }


        private void chkExtraCheese_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkOnion_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkMushrooms_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkOlives_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkTomatoes_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkGreenPeppers_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }


        private void rdThinCrust_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrustType();
        }

        private void rdThickCrust_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrustType();
        }


        private void rdEatIn_CheckedChanged(object sender, EventArgs e)
        {
            UpdateWhereToEat();
        }

        private void rdTakeOut_CheckedChanged(object sender, EventArgs e)
        {
            UpdateWhereToEat();
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
            if (!rbSmall.Checked && !rbMedium.Checked && !rbLarge.Checked)
            {
                MessageBox.Show("Please Select Pizza Size","Error",MessageBoxButtons.OK,MessageBoxIcon.Error);

                return;
            }
            if(!chkExtraCheese.Checked && !chkMushrooms.Checked && !chkOlives.Checked && !chkOnion.Checked 
                && !chkTomatoes.Checked && !chkGreenPeppers.Checked )
            {
                MessageBox.Show("Please Select At Least One Topping", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            if(!rbEatIn.Checked && !rbTakeOut.Checked)
            {
                MessageBox.Show("Please Select Where To Eat", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            if(!rbThinCrust.Checked && !rbThickCrust.Checked)
            {
                MessageBox.Show("Please Select Crust Type", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
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

        private void btnResetForm_Click(object sender, EventArgs e)
        {
            ResetForm();
        }


        private bool IsOrderComplete()
        {
            return (rbSmall.Checked || rbMedium.Checked || rbLarge.Checked)
                && (rbThinCrust.Checked || rbThickCrust.Checked)
                && (rbEatIn.Checked || rbTakeOut.Checked);
        }

        void UpdateOrderSummary()
        {
            if (IsOrderComplete())
            {
                lbPriceAnswer.ForeColor = Color.LimeGreen;
            }
            else
            {
                lbPriceAnswer.ForeColor = Color.Red;
            }
        }

        private void ResetOrderSummary()
        {
            lbSizeAnswer.Text = "No choose.";
            lbSizeAnswer.ForeColor = Color.Red;

            lbToppingsAnswer.Text = "No Toppings.";
            lbToppingsAnswer.ForeColor = Color.Red;

            lbCrustTybeAnswer.Text = "No choose.";
            lbCrustTybeAnswer.ForeColor = Color.Red;

            lbWhereToEatAnswer.Text = "No choose.";
            lbWhereToEatAnswer.ForeColor = Color.Red;

            lbPriceAnswer.Text = "0$";
            lbPriceAnswer.ForeColor = Color.Red;
        }

        void ResetForm()
        {
            // Reset all CheckBoxes and RadioButtons
            rbSmall.Checked = false;
            rbMedium.Checked = false;
            rbLarge.Checked = false;

            rbThinCrust.Checked = false;
            rbThickCrust.Checked = false;

            rbEatIn.Checked = false;
            rbTakeOut.Checked = false;

            chkExtraCheese.Checked = false;
            chkMushrooms.Checked = false;
            chkOlives.Checked = false;
            chkOnion.Checked = false;
            chkTomatoes.Checked = false;
            chkGreenPeppers.Checked = false;

            // Reset Order Summary
            ResetOrderSummary();

            // Enable all GroupBoxes and Buttons
            gbSize.Enabled = true;
            gbToppings.Enabled = true;
            gbCrustTybe.Enabled = true;
            gbWhereToEat.Enabled = true;
            btnOrderPizza.Enabled = true;
        }


        
    }
}
