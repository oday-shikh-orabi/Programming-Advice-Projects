namespace Pizza_Poject
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.lbTitle = new System.Windows.Forms.Label();
            this.gbSize = new System.Windows.Forms.GroupBox();
            this.rdLarge = new System.Windows.Forms.RadioButton();
            this.rdMedium = new System.Windows.Forms.RadioButton();
            this.rdSmall = new System.Windows.Forms.RadioButton();
            this.gbToppings = new System.Windows.Forms.GroupBox();
            this.chkGreenPeppers = new System.Windows.Forms.CheckBox();
            this.chkOlives = new System.Windows.Forms.CheckBox();
            this.chkOnion = new System.Windows.Forms.CheckBox();
            this.chkTomatoes = new System.Windows.Forms.CheckBox();
            this.chkMushrooms = new System.Windows.Forms.CheckBox();
            this.chkExtraCheese = new System.Windows.Forms.CheckBox();
            this.gbCrustTybe = new System.Windows.Forms.GroupBox();
            this.rdThickCrust = new System.Windows.Forms.RadioButton();
            this.rdThinCrust = new System.Windows.Forms.RadioButton();
            this.gbWhereToEat = new System.Windows.Forms.GroupBox();
            this.rdTakeOut = new System.Windows.Forms.RadioButton();
            this.rdEatIn = new System.Windows.Forms.RadioButton();
            this.btnOrderPizza = new System.Windows.Forms.Button();
            this.btnResetForm = new System.Windows.Forms.Button();
            this.gbOrderSize = new System.Windows.Forms.GroupBox();
            this.lbPriceAnswer = new System.Windows.Forms.Label();
            this.lbPrice = new System.Windows.Forms.Label();
            this.lbWhereToEatAnswer = new System.Windows.Forms.Label();
            this.lbWhereToEat = new System.Windows.Forms.Label();
            this.lbCrustTybeAnswer = new System.Windows.Forms.Label();
            this.lbCrustTybe = new System.Windows.Forms.Label();
            this.lbToppingsAnswer = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.lbSizeAnswer = new System.Windows.Forms.Label();
            this.lbSize1 = new System.Windows.Forms.Label();
            this.gbSize.SuspendLayout();
            this.gbToppings.SuspendLayout();
            this.gbCrustTybe.SuspendLayout();
            this.gbWhereToEat.SuspendLayout();
            this.gbOrderSize.SuspendLayout();
            this.SuspendLayout();
            // 
            // lbTitle
            // 
            this.lbTitle.AutoSize = true;
            this.lbTitle.BackColor = System.Drawing.Color.Transparent;
            this.lbTitle.Font = new System.Drawing.Font("Bernard MT Condensed", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbTitle.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(198)))), ((int)(((byte)(40)))), ((int)(((byte)(40)))));
            this.lbTitle.Location = new System.Drawing.Point(453, 9);
            this.lbTitle.Name = "lbTitle";
            this.lbTitle.Size = new System.Drawing.Size(410, 72);
            this.lbTitle.TabIndex = 20;
            this.lbTitle.Text = "Make Your Pizza";
            this.lbTitle.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // gbSize
            // 
            this.gbSize.BackColor = System.Drawing.Color.Transparent;
            this.gbSize.Controls.Add(this.rdLarge);
            this.gbSize.Controls.Add(this.rdMedium);
            this.gbSize.Controls.Add(this.rdSmall);
            this.gbSize.Font = new System.Drawing.Font("Segoe UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gbSize.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(139)))), ((int)(((byte)(47)))), ((int)(((byte)(28)))));
            this.gbSize.Location = new System.Drawing.Point(99, 116);
            this.gbSize.Name = "gbSize";
            this.gbSize.Size = new System.Drawing.Size(257, 127);
            this.gbSize.TabIndex = 0;
            this.gbSize.TabStop = false;
            this.gbSize.Text = "Size";
            // 
            // rdLarge
            // 
            this.rdLarge.AutoSize = true;
            this.rdLarge.Font = new System.Drawing.Font("Segoe UI Semibold", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rdLarge.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.rdLarge.Location = new System.Drawing.Point(45, 78);
            this.rdLarge.Name = "rdLarge";
            this.rdLarge.Size = new System.Drawing.Size(73, 27);
            this.rdLarge.TabIndex = 2;
            this.rdLarge.TabStop = true;
            this.rdLarge.Text = "Large";
            this.rdLarge.UseVisualStyleBackColor = true;
            this.rdLarge.CheckedChanged += new System.EventHandler(this.rdLarge_CheckedChanged);
            // 
            // rdMedium
            // 
            this.rdMedium.AutoSize = true;
            this.rdMedium.Font = new System.Drawing.Font("Segoe UI Semibold", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rdMedium.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.rdMedium.Location = new System.Drawing.Point(45, 51);
            this.rdMedium.Name = "rdMedium";
            this.rdMedium.Size = new System.Drawing.Size(95, 27);
            this.rdMedium.TabIndex = 1;
            this.rdMedium.TabStop = true;
            this.rdMedium.Text = "Medium";
            this.rdMedium.UseVisualStyleBackColor = true;
            this.rdMedium.CheckedChanged += new System.EventHandler(this.rdMedium_CheckedChanged);
            // 
            // rdSmall
            // 
            this.rdSmall.AutoSize = true;
            this.rdSmall.Font = new System.Drawing.Font("Segoe UI Semibold", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rdSmall.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.rdSmall.Location = new System.Drawing.Point(45, 24);
            this.rdSmall.Name = "rdSmall";
            this.rdSmall.Size = new System.Drawing.Size(72, 27);
            this.rdSmall.TabIndex = 0;
            this.rdSmall.TabStop = true;
            this.rdSmall.Text = "Small";
            this.rdSmall.UseVisualStyleBackColor = true;
            this.rdSmall.CheckedChanged += new System.EventHandler(this.rdSmall_CheckedChanged);
            // 
            // gbToppings
            // 
            this.gbToppings.BackColor = System.Drawing.Color.Transparent;
            this.gbToppings.Controls.Add(this.chkGreenPeppers);
            this.gbToppings.Controls.Add(this.chkOlives);
            this.gbToppings.Controls.Add(this.chkOnion);
            this.gbToppings.Controls.Add(this.chkTomatoes);
            this.gbToppings.Controls.Add(this.chkMushrooms);
            this.gbToppings.Controls.Add(this.chkExtraCheese);
            this.gbToppings.Font = new System.Drawing.Font("Segoe UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gbToppings.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(139)))), ((int)(((byte)(47)))), ((int)(((byte)(28)))));
            this.gbToppings.Location = new System.Drawing.Point(408, 116);
            this.gbToppings.Name = "gbToppings";
            this.gbToppings.Size = new System.Drawing.Size(514, 127);
            this.gbToppings.TabIndex = 1;
            this.gbToppings.TabStop = false;
            this.gbToppings.Text = "Toppings";
            // 
            // chkGreenPeppers
            // 
            this.chkGreenPeppers.AutoSize = true;
            this.chkGreenPeppers.Font = new System.Drawing.Font("Segoe UI Semibold", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkGreenPeppers.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.chkGreenPeppers.Location = new System.Drawing.Point(273, 80);
            this.chkGreenPeppers.Name = "chkGreenPeppers";
            this.chkGreenPeppers.Size = new System.Drawing.Size(143, 27);
            this.chkGreenPeppers.TabIndex = 5;
            this.chkGreenPeppers.TabStop = false;
            this.chkGreenPeppers.Text = "Green Peppers";
            this.chkGreenPeppers.UseVisualStyleBackColor = true;
            this.chkGreenPeppers.CheckedChanged += new System.EventHandler(this.chkGreenPeppers_CheckedChanged);
            // 
            // chkOlives
            // 
            this.chkOlives.AutoSize = true;
            this.chkOlives.Font = new System.Drawing.Font("Segoe UI Semibold", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkOlives.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.chkOlives.Location = new System.Drawing.Point(273, 53);
            this.chkOlives.Name = "chkOlives";
            this.chkOlives.Size = new System.Drawing.Size(78, 27);
            this.chkOlives.TabIndex = 3;
            this.chkOlives.TabStop = false;
            this.chkOlives.Text = "Olives";
            this.chkOlives.UseVisualStyleBackColor = true;
            this.chkOlives.CheckedChanged += new System.EventHandler(this.chkOlives_CheckedChanged);
            // 
            // chkOnion
            // 
            this.chkOnion.AutoSize = true;
            this.chkOnion.Font = new System.Drawing.Font("Segoe UI Semibold", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkOnion.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.chkOnion.Location = new System.Drawing.Point(273, 25);
            this.chkOnion.Name = "chkOnion";
            this.chkOnion.Size = new System.Drawing.Size(79, 27);
            this.chkOnion.TabIndex = 1;
            this.chkOnion.TabStop = false;
            this.chkOnion.Text = "Onion";
            this.chkOnion.UseVisualStyleBackColor = true;
            this.chkOnion.CheckedChanged += new System.EventHandler(this.chkOnion_CheckedChanged);
            // 
            // chkTomatoes
            // 
            this.chkTomatoes.AutoSize = true;
            this.chkTomatoes.Font = new System.Drawing.Font("Segoe UI Semibold", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkTomatoes.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.chkTomatoes.Location = new System.Drawing.Point(95, 80);
            this.chkTomatoes.Name = "chkTomatoes";
            this.chkTomatoes.Size = new System.Drawing.Size(105, 27);
            this.chkTomatoes.TabIndex = 4;
            this.chkTomatoes.TabStop = false;
            this.chkTomatoes.Text = "Tomatoes";
            this.chkTomatoes.UseVisualStyleBackColor = true;
            this.chkTomatoes.CheckedChanged += new System.EventHandler(this.chkTomatoes_CheckedChanged);
            // 
            // chkMushrooms
            // 
            this.chkMushrooms.AutoSize = true;
            this.chkMushrooms.Font = new System.Drawing.Font("Segoe UI Semibold", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkMushrooms.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.chkMushrooms.Location = new System.Drawing.Point(95, 53);
            this.chkMushrooms.Name = "chkMushrooms";
            this.chkMushrooms.Size = new System.Drawing.Size(123, 27);
            this.chkMushrooms.TabIndex = 2;
            this.chkMushrooms.TabStop = false;
            this.chkMushrooms.Text = "Mushrooms";
            this.chkMushrooms.UseVisualStyleBackColor = true;
            this.chkMushrooms.CheckedChanged += new System.EventHandler(this.chkMushrooms_CheckedChanged);
            // 
            // chkExtraCheese
            // 
            this.chkExtraCheese.AutoSize = true;
            this.chkExtraCheese.Font = new System.Drawing.Font("Segoe UI Semibold", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkExtraCheese.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.chkExtraCheese.Location = new System.Drawing.Point(95, 25);
            this.chkExtraCheese.Name = "chkExtraCheese";
            this.chkExtraCheese.Size = new System.Drawing.Size(122, 27);
            this.chkExtraCheese.TabIndex = 0;
            this.chkExtraCheese.Text = "Extra Chees";
            this.chkExtraCheese.UseVisualStyleBackColor = true;
            this.chkExtraCheese.CheckedChanged += new System.EventHandler(this.chkExtraCheese_CheckedChanged);
            // 
            // gbCrustTybe
            // 
            this.gbCrustTybe.BackColor = System.Drawing.Color.Transparent;
            this.gbCrustTybe.Controls.Add(this.rdThickCrust);
            this.gbCrustTybe.Controls.Add(this.rdThinCrust);
            this.gbCrustTybe.Font = new System.Drawing.Font("Segoe UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gbCrustTybe.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(139)))), ((int)(((byte)(47)))), ((int)(((byte)(28)))));
            this.gbCrustTybe.Location = new System.Drawing.Point(99, 265);
            this.gbCrustTybe.Name = "gbCrustTybe";
            this.gbCrustTybe.Size = new System.Drawing.Size(257, 118);
            this.gbCrustTybe.TabIndex = 2;
            this.gbCrustTybe.TabStop = false;
            this.gbCrustTybe.Text = "Crust Type";
            // 
            // rdThickCrust
            // 
            this.rdThickCrust.AutoSize = true;
            this.rdThickCrust.Font = new System.Drawing.Font("Segoe UI Semibold", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rdThickCrust.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.rdThickCrust.Location = new System.Drawing.Point(43, 59);
            this.rdThickCrust.Name = "rdThickCrust";
            this.rdThickCrust.Size = new System.Drawing.Size(116, 27);
            this.rdThickCrust.TabIndex = 1;
            this.rdThickCrust.Text = "Thick Crust";
            this.rdThickCrust.UseVisualStyleBackColor = true;
            this.rdThickCrust.CheckedChanged += new System.EventHandler(this.rdThickCrust_CheckedChanged);
            // 
            // rdThinCrust
            // 
            this.rdThinCrust.AutoSize = true;
            this.rdThinCrust.Font = new System.Drawing.Font("Segoe UI Semibold", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rdThinCrust.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.rdThinCrust.Location = new System.Drawing.Point(43, 32);
            this.rdThinCrust.Name = "rdThinCrust";
            this.rdThinCrust.Size = new System.Drawing.Size(109, 27);
            this.rdThinCrust.TabIndex = 0;
            this.rdThinCrust.TabStop = true;
            this.rdThinCrust.Text = "Thin Crust";
            this.rdThinCrust.UseVisualStyleBackColor = true;
            this.rdThinCrust.CheckedChanged += new System.EventHandler(this.rdThinCrust_CheckedChanged);
            // 
            // gbWhereToEat
            // 
            this.gbWhereToEat.BackColor = System.Drawing.Color.Transparent;
            this.gbWhereToEat.Controls.Add(this.rdTakeOut);
            this.gbWhereToEat.Controls.Add(this.rdEatIn);
            this.gbWhereToEat.Font = new System.Drawing.Font("Segoe UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gbWhereToEat.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(139)))), ((int)(((byte)(47)))), ((int)(((byte)(28)))));
            this.gbWhereToEat.Location = new System.Drawing.Point(408, 272);
            this.gbWhereToEat.Name = "gbWhereToEat";
            this.gbWhereToEat.Size = new System.Drawing.Size(514, 111);
            this.gbWhereToEat.TabIndex = 3;
            this.gbWhereToEat.TabStop = false;
            this.gbWhereToEat.Text = "Where To Eat";
            // 
            // rdTakeOut
            // 
            this.rdTakeOut.AutoSize = true;
            this.rdTakeOut.Font = new System.Drawing.Font("Segoe UI Semibold", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rdTakeOut.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.rdTakeOut.Location = new System.Drawing.Point(273, 46);
            this.rdTakeOut.Name = "rdTakeOut";
            this.rdTakeOut.Size = new System.Drawing.Size(96, 27);
            this.rdTakeOut.TabIndex = 1;
            this.rdTakeOut.Text = "Take out";
            this.rdTakeOut.UseVisualStyleBackColor = true;
            this.rdTakeOut.CheckedChanged += new System.EventHandler(this.rdTakeOut_CheckedChanged);
            // 
            // rdEatIn
            // 
            this.rdEatIn.AutoSize = true;
            this.rdEatIn.Font = new System.Drawing.Font("Segoe UI Semibold", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rdEatIn.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.rdEatIn.Location = new System.Drawing.Point(95, 46);
            this.rdEatIn.Name = "rdEatIn";
            this.rdEatIn.Size = new System.Drawing.Size(74, 27);
            this.rdEatIn.TabIndex = 0;
            this.rdEatIn.TabStop = true;
            this.rdEatIn.Text = "Eat in";
            this.rdEatIn.UseVisualStyleBackColor = true;
            this.rdEatIn.CheckedChanged += new System.EventHandler(this.rdEatIn_CheckedChanged);
            // 
            // btnOrderPizza
            // 
            this.btnOrderPizza.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(142)))), ((int)(((byte)(60)))));
            this.btnOrderPizza.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnOrderPizza.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnOrderPizza.FlatAppearance.BorderSize = 0;
            this.btnOrderPizza.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnOrderPizza.Font = new System.Drawing.Font("Segoe UI", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnOrderPizza.ForeColor = System.Drawing.Color.White;
            this.btnOrderPizza.Location = new System.Drawing.Point(450, 435);
            this.btnOrderPizza.Name = "btnOrderPizza";
            this.btnOrderPizza.Size = new System.Drawing.Size(177, 55);
            this.btnOrderPizza.TabIndex = 5;
            this.btnOrderPizza.Text = "Order Pizza";
            this.btnOrderPizza.UseVisualStyleBackColor = false;
            this.btnOrderPizza.Click += new System.EventHandler(this.btnOrderPizza_Click);
            this.btnOrderPizza.MouseEnter += new System.EventHandler(this.btnOrderPizza_MouseEnter);
            this.btnOrderPizza.MouseLeave += new System.EventHandler(this.btnOrderPizza_MouseLeave);
            // 
            // btnResetForm
            // 
            this.btnResetForm.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(198)))), ((int)(((byte)(40)))), ((int)(((byte)(40)))));
            this.btnResetForm.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnResetForm.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnResetForm.FlatAppearance.BorderSize = 0;
            this.btnResetForm.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnResetForm.Font = new System.Drawing.Font("Segoe UI", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnResetForm.ForeColor = System.Drawing.Color.White;
            this.btnResetForm.Location = new System.Drawing.Point(675, 435);
            this.btnResetForm.Name = "btnResetForm";
            this.btnResetForm.Size = new System.Drawing.Size(177, 55);
            this.btnResetForm.TabIndex = 4;
            this.btnResetForm.Text = "Reset Form";
            this.btnResetForm.UseVisualStyleBackColor = false;
            this.btnResetForm.Click += new System.EventHandler(this.btnResetForm_Click);
            this.btnResetForm.MouseEnter += new System.EventHandler(this.btnResetForm_MouseEnter);
            this.btnResetForm.MouseLeave += new System.EventHandler(this.btnResetForm_MouseLeave);
            // 
            // gbOrderSize
            // 
            this.gbOrderSize.BackColor = System.Drawing.Color.Transparent;
            this.gbOrderSize.Controls.Add(this.lbPriceAnswer);
            this.gbOrderSize.Controls.Add(this.lbPrice);
            this.gbOrderSize.Controls.Add(this.lbWhereToEatAnswer);
            this.gbOrderSize.Controls.Add(this.lbWhereToEat);
            this.gbOrderSize.Controls.Add(this.lbCrustTybeAnswer);
            this.gbOrderSize.Controls.Add(this.lbCrustTybe);
            this.gbOrderSize.Controls.Add(this.lbToppingsAnswer);
            this.gbOrderSize.Controls.Add(this.label2);
            this.gbOrderSize.Controls.Add(this.lbSizeAnswer);
            this.gbOrderSize.Controls.Add(this.lbSize1);
            this.gbOrderSize.Cursor = System.Windows.Forms.Cursors.WaitCursor;
            this.gbOrderSize.Font = new System.Drawing.Font("Segoe UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gbOrderSize.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(139)))), ((int)(((byte)(47)))), ((int)(((byte)(28)))));
            this.gbOrderSize.Location = new System.Drawing.Point(970, 116);
            this.gbOrderSize.Name = "gbOrderSize";
            this.gbOrderSize.Size = new System.Drawing.Size(342, 341);
            this.gbOrderSize.TabIndex = 6;
            this.gbOrderSize.TabStop = false;
            this.gbOrderSize.Text = "     Order Summary";
            this.gbOrderSize.UseWaitCursor = true;
            // 
            // lbPriceAnswer
            // 
            this.lbPriceAnswer.AutoSize = true;
            this.lbPriceAnswer.Font = new System.Drawing.Font("Stencil", 22.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbPriceAnswer.ForeColor = System.Drawing.Color.Red;
            this.lbPriceAnswer.Location = new System.Drawing.Point(148, 293);
            this.lbPriceAnswer.Name = "lbPriceAnswer";
            this.lbPriceAnswer.Size = new System.Drawing.Size(63, 44);
            this.lbPriceAnswer.TabIndex = 9;
            this.lbPriceAnswer.Text = "0$";
            this.lbPriceAnswer.UseWaitCursor = true;
            // 
            // lbPrice
            // 
            this.lbPrice.AutoSize = true;
            this.lbPrice.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbPrice.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.lbPrice.Location = new System.Drawing.Point(31, 292);
            this.lbPrice.Name = "lbPrice";
            this.lbPrice.Size = new System.Drawing.Size(58, 21);
            this.lbPrice.TabIndex = 8;
            this.lbPrice.Text = "Price:";
            this.lbPrice.UseWaitCursor = true;
            // 
            // lbWhereToEatAnswer
            // 
            this.lbWhereToEatAnswer.AutoSize = true;
            this.lbWhereToEatAnswer.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbWhereToEatAnswer.ForeColor = System.Drawing.Color.Red;
            this.lbWhereToEatAnswer.Location = new System.Drawing.Point(137, 262);
            this.lbWhereToEatAnswer.Name = "lbWhereToEatAnswer";
            this.lbWhereToEatAnswer.Size = new System.Drawing.Size(92, 21);
            this.lbWhereToEatAnswer.TabIndex = 7;
            this.lbWhereToEatAnswer.Text = "No choose.";
            this.lbWhereToEatAnswer.UseWaitCursor = true;
            // 
            // lbWhereToEat
            // 
            this.lbWhereToEat.AutoSize = true;
            this.lbWhereToEat.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbWhereToEat.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.lbWhereToEat.Location = new System.Drawing.Point(31, 234);
            this.lbWhereToEat.Name = "lbWhereToEat";
            this.lbWhereToEat.Size = new System.Drawing.Size(129, 21);
            this.lbWhereToEat.TabIndex = 6;
            this.lbWhereToEat.Text = "Where To Eat:";
            this.lbWhereToEat.UseWaitCursor = true;
            // 
            // lbCrustTybeAnswer
            // 
            this.lbCrustTybeAnswer.AutoSize = true;
            this.lbCrustTybeAnswer.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbCrustTybeAnswer.ForeColor = System.Drawing.Color.Red;
            this.lbCrustTybeAnswer.Location = new System.Drawing.Point(137, 190);
            this.lbCrustTybeAnswer.Name = "lbCrustTybeAnswer";
            this.lbCrustTybeAnswer.Size = new System.Drawing.Size(92, 21);
            this.lbCrustTybeAnswer.TabIndex = 5;
            this.lbCrustTybeAnswer.Text = "No choose.";
            this.lbCrustTybeAnswer.UseWaitCursor = true;
            // 
            // lbCrustTybe
            // 
            this.lbCrustTybe.AutoSize = true;
            this.lbCrustTybe.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbCrustTybe.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.lbCrustTybe.Location = new System.Drawing.Point(31, 190);
            this.lbCrustTybe.Name = "lbCrustTybe";
            this.lbCrustTybe.Size = new System.Drawing.Size(107, 21);
            this.lbCrustTybe.TabIndex = 4;
            this.lbCrustTybe.Text = "Crust Tybe:";
            this.lbCrustTybe.UseWaitCursor = true;
            // 
            // lbToppingsAnswer
            // 
            this.lbToppingsAnswer.AutoSize = true;
            this.lbToppingsAnswer.Cursor = System.Windows.Forms.Cursors.WaitCursor;
            this.lbToppingsAnswer.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbToppingsAnswer.ForeColor = System.Drawing.Color.Red;
            this.lbToppingsAnswer.Location = new System.Drawing.Point(84, 111);
            this.lbToppingsAnswer.Name = "lbToppingsAnswer";
            this.lbToppingsAnswer.Size = new System.Drawing.Size(107, 21);
            this.lbToppingsAnswer.TabIndex = 3;
            this.lbToppingsAnswer.Text = "No Toppings.";
            this.lbToppingsAnswer.UseWaitCursor = true;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.label2.Location = new System.Drawing.Point(31, 78);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(95, 21);
            this.label2.TabIndex = 2;
            this.label2.Text = "Toppings:";
            this.label2.UseWaitCursor = true;
            // 
            // lbSizeAnswer
            // 
            this.lbSizeAnswer.AutoSize = true;
            this.lbSizeAnswer.Cursor = System.Windows.Forms.Cursors.WaitCursor;
            this.lbSizeAnswer.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbSizeAnswer.ForeColor = System.Drawing.Color.Red;
            this.lbSizeAnswer.Location = new System.Drawing.Point(84, 35);
            this.lbSizeAnswer.Name = "lbSizeAnswer";
            this.lbSizeAnswer.Size = new System.Drawing.Size(92, 21);
            this.lbSizeAnswer.TabIndex = 1;
            this.lbSizeAnswer.Text = "No choose.";
            this.lbSizeAnswer.UseWaitCursor = true;
            // 
            // lbSize1
            // 
            this.lbSize1.AutoSize = true;
            this.lbSize1.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbSize1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(89)))), ((int)(((byte)(53)))), ((int)(((byte)(34)))));
            this.lbSize1.Location = new System.Drawing.Point(31, 34);
            this.lbSize1.Name = "lbSize1";
            this.lbSize1.Size = new System.Drawing.Size(56, 21);
            this.lbSize1.TabIndex = 0;
            this.lbSize1.Text = "Size: ";
            this.lbSize1.UseWaitCursor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::Pizza_Poject.Properties.Resources.Pizza_Order_Form_Card_Layout;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(1369, 566);
            this.Controls.Add(this.gbOrderSize);
            this.Controls.Add(this.btnResetForm);
            this.Controls.Add(this.btnOrderPizza);
            this.Controls.Add(this.gbWhereToEat);
            this.Controls.Add(this.gbCrustTybe);
            this.Controls.Add(this.gbToppings);
            this.Controls.Add(this.gbSize);
            this.Controls.Add(this.lbTitle);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Pizza Project";
            this.gbSize.ResumeLayout(false);
            this.gbSize.PerformLayout();
            this.gbToppings.ResumeLayout(false);
            this.gbToppings.PerformLayout();
            this.gbCrustTybe.ResumeLayout(false);
            this.gbCrustTybe.PerformLayout();
            this.gbWhereToEat.ResumeLayout(false);
            this.gbWhereToEat.PerformLayout();
            this.gbOrderSize.ResumeLayout(false);
            this.gbOrderSize.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lbTitle;
        private System.Windows.Forms.GroupBox gbSize;
        private System.Windows.Forms.RadioButton rdLarge;
        private System.Windows.Forms.RadioButton rdMedium;
        private System.Windows.Forms.RadioButton rdSmall;
        private System.Windows.Forms.GroupBox gbToppings;
        private System.Windows.Forms.CheckBox chkTomatoes;
        private System.Windows.Forms.CheckBox chkMushrooms;
        private System.Windows.Forms.CheckBox chkExtraCheese;
        private System.Windows.Forms.CheckBox chkGreenPeppers;
        private System.Windows.Forms.CheckBox chkOlives;
        private System.Windows.Forms.CheckBox chkOnion;
        private System.Windows.Forms.GroupBox gbCrustTybe;
        private System.Windows.Forms.RadioButton rdThinCrust;
        private System.Windows.Forms.RadioButton rdThickCrust;
        private System.Windows.Forms.GroupBox gbWhereToEat;
        private System.Windows.Forms.RadioButton rdTakeOut;
        private System.Windows.Forms.RadioButton rdEatIn;
        private System.Windows.Forms.Button btnOrderPizza;
        private System.Windows.Forms.Button btnResetForm;
        private System.Windows.Forms.GroupBox gbOrderSize;
        private System.Windows.Forms.Label lbSize1;
        private System.Windows.Forms.Label lbSizeAnswer;
        private System.Windows.Forms.Label lbToppingsAnswer;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label lbCrustTybe;
        private System.Windows.Forms.Label lbPrice;
        private System.Windows.Forms.Label lbWhereToEatAnswer;
        private System.Windows.Forms.Label lbWhereToEat;
        private System.Windows.Forms.Label lbCrustTybeAnswer;
        private System.Windows.Forms.Label lbPriceAnswer;
    }
}

