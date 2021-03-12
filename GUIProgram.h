#pragma once

namespace MiniPhotoshop3
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class GUIProgram : public System::Windows::Forms::Form
	{
	public:
		GUIProgram(void)
		{
			InitializeComponent();
		}

	protected:
		~GUIProgram()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::MenuStrip^ menuStrip;

	private: System::Windows::Forms::OpenFileDialog^ dialog;
	
	private: System::Windows::Forms::Button^ openPPMButton;
	private: System::Windows::Forms::Button^ openPBMButton;
	private: System::Windows::Forms::Button^ openPGMButton;
	private: System::Windows::Forms::Button^ openBMPButton;

	private: System::Windows::Forms::Button^ toNegativeButton;
	private: System::Windows::Forms::Button^ toGraysButton;
	private: System::Windows::Forms::Button^ imgAddButton;
	private: System::Windows::Forms::Button^ imgSubstButton;
	private: System::Windows::Forms::Button^ showButton;

	private: System::Windows::Forms::Button^ operNOTButton;
	private: System::Windows::Forms::Button^ operANDButton;
	private: System::Windows::Forms::Button^ operORButton;
	private: System::Windows::Forms::Button^ operXORButton;

	private: System::Windows::Forms::Button^ imgMoveButton;
	private: System::Windows::Forms::Button^ imgRotateButton;
	private: System::Windows::Forms::Button^ imgFlipButton;
	private: System::Windows::Forms::Button^ imgZoomButton;

	private: System::Windows::Forms::Button^ brighteningButton;
	private: System::Windows::Forms::Button^ stretchingButton;
	private: System::Windows::Forms::Button^ logTransformButton;
	private: System::Windows::Forms::Button^ logInverseButton;
	private: System::Windows::Forms::Button^ powerTransformButton;
	private: System::Windows::Forms::Button^ graySlicingButton;
	private: System::Windows::Forms::Button^ bitpSlicing;
	private: System::Windows::Forms::Button^ histEqButton;
	private: System::Windows::Forms::Button^ histoSpecButton;
	private: System::Windows::Forms::Button^ convolutionButton;
	private: System::Windows::Forms::Button^ blurButton;
	private: System::Windows::Forms::Button^ sharpeningButton;
	private: System::Windows::Forms::Button^ noiseButton;

	private: System::Windows::Forms::Button^ firstMenuButton;
	private: System::Windows::Forms::Button^ secondMenuButton;
	private: System::Windows::Forms::Button^ thirdMenuButton;

	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:
		System::ComponentModel::Container ^components;

		void InitializeComponent(void)
		{
			this->openPPMButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->openPBMButton = (gcnew System::Windows::Forms::Button());
			this->openPGMButton = (gcnew System::Windows::Forms::Button());
			this->openBMPButton = (gcnew System::Windows::Forms::Button());
			this->toNegativeButton = (gcnew System::Windows::Forms::Button());
			this->toGraysButton = (gcnew System::Windows::Forms::Button());
			this->imgAddButton = (gcnew System::Windows::Forms::Button());
			this->imgSubstButton = (gcnew System::Windows::Forms::Button());
			this->showButton = (gcnew System::Windows::Forms::Button());
			this->operNOTButton = (gcnew System::Windows::Forms::Button());
			this->operANDButton = (gcnew System::Windows::Forms::Button());
			this->operORButton = (gcnew System::Windows::Forms::Button());
			this->operXORButton = (gcnew System::Windows::Forms::Button());
			this->imgMoveButton = (gcnew System::Windows::Forms::Button());
			this->imgRotateButton = (gcnew System::Windows::Forms::Button());
			this->imgFlipButton = (gcnew System::Windows::Forms::Button());
			this->imgZoomButton = (gcnew System::Windows::Forms::Button());
			this->brighteningButton = (gcnew System::Windows::Forms::Button());
			this->stretchingButton = (gcnew System::Windows::Forms::Button());
			this->logTransformButton = (gcnew System::Windows::Forms::Button());
			this->logInverseButton = (gcnew System::Windows::Forms::Button());
			this->powerTransformButton = (gcnew System::Windows::Forms::Button());
			this->graySlicingButton = (gcnew System::Windows::Forms::Button());
			this->bitpSlicing = (gcnew System::Windows::Forms::Button());
			this->histEqButton = (gcnew System::Windows::Forms::Button());
			this->histoSpecButton = (gcnew System::Windows::Forms::Button());
			this->convolutionButton = (gcnew System::Windows::Forms::Button());
			this->blurButton = (gcnew System::Windows::Forms::Button());
			this->sharpeningButton = (gcnew System::Windows::Forms::Button());
			this->noiseButton = (gcnew System::Windows::Forms::Button());
			this->firstMenuButton = (gcnew System::Windows::Forms::Button());
			this->secondMenuButton = (gcnew System::Windows::Forms::Button());
			this->thirdMenuButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// openPPMButton
			// 
			this->openPPMButton->Location = System::Drawing::Point(0, 0);
			this->openPPMButton->Name = L"openPPMButton";
			this->openPPMButton->Size = System::Drawing::Size(80, 23);
			this->openPPMButton->TabIndex = 2;
			this->openPPMButton->Text = L"Open PPM";
			this->openPPMButton->UseVisualStyleBackColor = true;
			// 
			// menuStrip
			// 
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(792, 24);
			this->menuStrip->TabIndex = 3;
			this->menuStrip->Text = L"T";
			// 
			// openPBMButton
			// 
			this->openPBMButton->Location = System::Drawing::Point(172, 0);
			this->openPBMButton->Name = L"openPBMButton";
			this->openPBMButton->Size = System::Drawing::Size(80, 23);
			this->openPBMButton->TabIndex = 4;
			this->openPBMButton->Text = L"Open PBM";
			this->openPBMButton->UseVisualStyleBackColor = true;
			// 
			// openPGMButton
			// 
			this->openPGMButton->Location = System::Drawing::Point(86, 0);
			this->openPGMButton->Name = L"openPGMButton";
			this->openPGMButton->Size = System::Drawing::Size(80, 23);
			this->openPGMButton->TabIndex = 5;
			this->openPGMButton->Text = L"Open PGM";
			this->openPGMButton->UseVisualStyleBackColor = true;
			// 
			// openBMPButton
			// 
			this->openBMPButton->Location = System::Drawing::Point(258, 0);
			this->openBMPButton->Name = L"openBMPButton";
			this->openBMPButton->Size = System::Drawing::Size(80, 23);
			this->openBMPButton->TabIndex = 6;
			this->openBMPButton->Text = L"Open BMP";
			this->openBMPButton->UseVisualStyleBackColor = true;
			// 
			// toNegativeButton
			// 
			this->toNegativeButton->Location = System::Drawing::Point(0, 74);
			this->toNegativeButton->Name = L"toNegativeButton";
			this->toNegativeButton->Size = System::Drawing::Size(120, 23);
			this->toNegativeButton->TabIndex = 7;
			this->toNegativeButton->Text = L"Negative Color";
			this->toNegativeButton->UseVisualStyleBackColor = true;
			// 
			// toGraysButton
			// 
			this->toGraysButton->Location = System::Drawing::Point(0, 103);
			this->toGraysButton->Name = L"toGraysButton";
			this->toGraysButton->Size = System::Drawing::Size(120, 23);
			this->toGraysButton->TabIndex = 8;
			this->toGraysButton->Text = L"Grayscale";
			this->toGraysButton->UseVisualStyleBackColor = true;
			// 
			// imgAddButton
			// 
			this->imgAddButton->Location = System::Drawing::Point(0, 132);
			this->imgAddButton->Name = L"imgAddButton";
			this->imgAddButton->Size = System::Drawing::Size(120, 23);
			this->imgAddButton->TabIndex = 9;
			this->imgAddButton->Text = L"Addition";
			this->imgAddButton->UseVisualStyleBackColor = true;
			// 
			// imgSubstButton
			// 
			this->imgSubstButton->Location = System::Drawing::Point(0, 161);
			this->imgSubstButton->Name = L"imgSubstButton";
			this->imgSubstButton->Size = System::Drawing::Size(120, 23);
			this->imgSubstButton->TabIndex = 10;
			this->imgSubstButton->Text = L"Subtraction";
			this->imgSubstButton->UseVisualStyleBackColor = true;
			// 
			// showButton
			// 
			this->showButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->showButton->Location = System::Drawing::Point(200, 450);
			this->showButton->Margin = System::Windows::Forms::Padding(0);
			this->showButton->Name = L"showButton";
			this->showButton->Size = System::Drawing::Size(400, 100);
			this->showButton->TabIndex = 11;
			this->showButton->Text = L"SHOW IMAGE";
			this->showButton->UseVisualStyleBackColor = true;
			this->showButton->Click += gcnew System::EventHandler(this, &GUIProgram::showButton_Click);
			// 
			// operNOTButton
			// 
			this->operNOTButton->Location = System::Drawing::Point(0, 219);
			this->operNOTButton->Name = L"operNOTButton";
			this->operNOTButton->Size = System::Drawing::Size(60, 23);
			this->operNOTButton->TabIndex = 12;
			this->operNOTButton->Text = L"NOT";
			this->operNOTButton->UseVisualStyleBackColor = true;
			// 
			// operANDButton
			// 
			this->operANDButton->Location = System::Drawing::Point(0, 190);
			this->operANDButton->Name = L"operANDButton";
			this->operANDButton->Size = System::Drawing::Size(60, 23);
			this->operANDButton->TabIndex = 13;
			this->operANDButton->Text = L"AND";
			this->operANDButton->UseVisualStyleBackColor = true;
			// 
			// operORButton
			// 
			this->operORButton->Location = System::Drawing::Point(0, 248);
			this->operORButton->Name = L"operORButton";
			this->operORButton->Size = System::Drawing::Size(60, 23);
			this->operORButton->TabIndex = 14;
			this->operORButton->Text = L"OR";
			this->operORButton->UseVisualStyleBackColor = true;
			// 
			// operXORButton
			// 
			this->operXORButton->Location = System::Drawing::Point(0, 277);
			this->operXORButton->Name = L"operXORButton";
			this->operXORButton->Size = System::Drawing::Size(60, 23);
			this->operXORButton->TabIndex = 15;
			this->operXORButton->Text = L"XOR";
			this->operXORButton->UseVisualStyleBackColor = true;
			// 
			// imgMoveButton
			// 
			this->imgMoveButton->Location = System::Drawing::Point(0, 74);
			this->imgMoveButton->Name = L"imgMoveButton";
			this->imgMoveButton->Size = System::Drawing::Size(60, 23);
			this->imgMoveButton->TabIndex = 16;
			this->imgMoveButton->Text = L"Move";
			this->imgMoveButton->UseVisualStyleBackColor = true;
			// 
			// imgRotateButton
			// 
			this->imgRotateButton->Location = System::Drawing::Point(0, 132);
			this->imgRotateButton->Name = L"imgRotateButton";
			this->imgRotateButton->Size = System::Drawing::Size(60, 23);
			this->imgRotateButton->TabIndex = 17;
			this->imgRotateButton->Text = L"Rotate";
			this->imgRotateButton->UseVisualStyleBackColor = true;
			// 
			// imgFlipButton
			// 
			this->imgFlipButton->Location = System::Drawing::Point(0, 103);
			this->imgFlipButton->Name = L"imgFlipButton";
			this->imgFlipButton->Size = System::Drawing::Size(60, 23);
			this->imgFlipButton->TabIndex = 18;
			this->imgFlipButton->Text = L"Flip";
			this->imgFlipButton->UseVisualStyleBackColor = true;
			// 
			// imgZoomButton
			// 
			this->imgZoomButton->Location = System::Drawing::Point(0, 161);
			this->imgZoomButton->Name = L"imgZoomButton";
			this->imgZoomButton->Size = System::Drawing::Size(60, 23);
			this->imgZoomButton->TabIndex = 19;
			this->imgZoomButton->Text = L"Zoom";
			this->imgZoomButton->UseVisualStyleBackColor = true;
			// 
			// brighteningButton
			// 
			this->brighteningButton->Location = System::Drawing::Point(0, 74);
			this->brighteningButton->Name = L"brighteningButton";
			this->brighteningButton->Size = System::Drawing::Size(120, 23);
			this->brighteningButton->TabIndex = 20;
			this->brighteningButton->Text = L"Brightening";
			this->brighteningButton->UseVisualStyleBackColor = true;
			// 
			// stretchingButton
			// 
			this->stretchingButton->Location = System::Drawing::Point(0, 103);
			this->stretchingButton->Name = L"stretchingButton";
			this->stretchingButton->Size = System::Drawing::Size(120, 23);
			this->stretchingButton->TabIndex = 21;
			this->stretchingButton->Text = L"Contrast Stretching";
			this->stretchingButton->UseVisualStyleBackColor = true;
			// 
			// logTransformButton
			// 
			this->logTransformButton->Location = System::Drawing::Point(0, 132);
			this->logTransformButton->Name = L"logTransformButton";
			this->logTransformButton->Size = System::Drawing::Size(120, 23);
			this->logTransformButton->TabIndex = 22;
			this->logTransformButton->Text = L"Log Transform";
			this->logTransformButton->UseVisualStyleBackColor = true;
			// 
			// logInverseButton
			// 
			this->logInverseButton->Location = System::Drawing::Point(0, 161);
			this->logInverseButton->Name = L"logInverseButton";
			this->logInverseButton->Size = System::Drawing::Size(120, 23);
			this->logInverseButton->TabIndex = 23;
			this->logInverseButton->Text = L"Log Inverse";
			this->logInverseButton->UseVisualStyleBackColor = true;
			// 
			// powerTransformButton
			// 
			this->powerTransformButton->Location = System::Drawing::Point(0, 190);
			this->powerTransformButton->Name = L"powerTransformButton";
			this->powerTransformButton->Size = System::Drawing::Size(120, 23);
			this->powerTransformButton->TabIndex = 24;
			this->powerTransformButton->Text = L"Power Transform";
			this->powerTransformButton->UseVisualStyleBackColor = true;
			// 
			// graySlicingButton
			// 
			this->graySlicingButton->Location = System::Drawing::Point(0, 219);
			this->graySlicingButton->Name = L"graySlicingButton";
			this->graySlicingButton->Size = System::Drawing::Size(120, 23);
			this->graySlicingButton->TabIndex = 25;
			this->graySlicingButton->Text = L"Gray-level Slicing";
			this->graySlicingButton->UseVisualStyleBackColor = true;
			// 
			// bitpSlicing
			// 
			this->bitpSlicing->Location = System::Drawing::Point(0, 248);
			this->bitpSlicing->Name = L"bitpSlicing";
			this->bitpSlicing->Size = System::Drawing::Size(120, 23);
			this->bitpSlicing->TabIndex = 26;
			this->bitpSlicing->Text = L"Bit-plane Slicing";
			this->bitpSlicing->UseVisualStyleBackColor = true;
			// 
			// histEqButton
			// 
			this->histEqButton->Location = System::Drawing::Point(0, 306);
			this->histEqButton->Name = L"histEqButton";
			this->histEqButton->Size = System::Drawing::Size(160, 23);
			this->histEqButton->TabIndex = 27;
			this->histEqButton->Text = L"Histogram Equalization";
			this->histEqButton->UseVisualStyleBackColor = true;
			// 
			// histoSpecButton
			// 
			this->histoSpecButton->Location = System::Drawing::Point(0, 277);
			this->histoSpecButton->Name = L"histoSpecButton";
			this->histoSpecButton->Size = System::Drawing::Size(160, 23);
			this->histoSpecButton->TabIndex = 28;
			this->histoSpecButton->Text = L"Histogram Specification";
			this->histoSpecButton->UseVisualStyleBackColor = true;
			// 
			// convolutionButton
			// 
			this->convolutionButton->Location = System::Drawing::Point(0, 190);
			this->convolutionButton->Name = L"convolutionButton";
			this->convolutionButton->Size = System::Drawing::Size(120, 23);
			this->convolutionButton->TabIndex = 29;
			this->convolutionButton->Text = L"Convolution";
			this->convolutionButton->UseVisualStyleBackColor = true;
			// 
			// blurButton
			// 
			this->blurButton->Location = System::Drawing::Point(0, 219);
			this->blurButton->Name = L"blurButton";
			this->blurButton->Size = System::Drawing::Size(120, 23);
			this->blurButton->TabIndex = 30;
			this->blurButton->Text = L"Blurring";
			this->blurButton->UseVisualStyleBackColor = true;
			// 
			// sharpeningButton
			// 
			this->sharpeningButton->Location = System::Drawing::Point(0, 248);
			this->sharpeningButton->Name = L"sharpeningButton";
			this->sharpeningButton->Size = System::Drawing::Size(120, 23);
			this->sharpeningButton->TabIndex = 31;
			this->sharpeningButton->Text = L"Sharpening";
			this->sharpeningButton->UseVisualStyleBackColor = true;
			// 
			// noiseButton
			// 
			this->noiseButton->Location = System::Drawing::Point(0, 277);
			this->noiseButton->Name = L"noiseButton";
			this->noiseButton->Size = System::Drawing::Size(120, 23);
			this->noiseButton->TabIndex = 32;
			this->noiseButton->Text = L"Noise Removal";
			this->noiseButton->UseVisualStyleBackColor = true;
			// 
			// firstMenuButton
			// 
			this->firstMenuButton->Location = System::Drawing::Point(0, 45);
			this->firstMenuButton->Name = L"firstMenuButton";
			this->firstMenuButton->Size = System::Drawing::Size(40, 23);
			this->firstMenuButton->TabIndex = 33;
			this->firstMenuButton->Text = L"1";
			this->firstMenuButton->UseVisualStyleBackColor = true;
			this->firstMenuButton->Click += gcnew System::EventHandler(this, &GUIProgram::firstMenuButton_Click);
			// 
			// secondMenuButton
			// 
			this->secondMenuButton->Location = System::Drawing::Point(46, 45);
			this->secondMenuButton->Name = L"secondMenuButton";
			this->secondMenuButton->Size = System::Drawing::Size(40, 23);
			this->secondMenuButton->TabIndex = 34;
			this->secondMenuButton->Text = L"2";
			this->secondMenuButton->UseVisualStyleBackColor = true;
			this->secondMenuButton->Click += gcnew System::EventHandler(this, &GUIProgram::secondMenuButton_Click);
			// 
			// thirdMenuButton
			// 
			this->thirdMenuButton->Location = System::Drawing::Point(92, 45);
			this->thirdMenuButton->Name = L"thirdMenuButton";
			this->thirdMenuButton->Size = System::Drawing::Size(40, 23);
			this->thirdMenuButton->TabIndex = 35;
			this->thirdMenuButton->Text = L"3";
			this->thirdMenuButton->UseVisualStyleBackColor = true;
			this->thirdMenuButton->Click += gcnew System::EventHandler(this, &GUIProgram::thirdMenuButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(173, 30);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(426, 298);
			this->pictureBox1->TabIndex = 36;
			this->pictureBox1->TabStop = false;
			// 
			// GUIProgram
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(792, 573);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->thirdMenuButton);
			this->Controls->Add(this->secondMenuButton);
			this->Controls->Add(this->firstMenuButton);
			this->Controls->Add(this->noiseButton);
			this->Controls->Add(this->sharpeningButton);
			this->Controls->Add(this->blurButton);
			this->Controls->Add(this->convolutionButton);
			this->Controls->Add(this->histoSpecButton);
			this->Controls->Add(this->histEqButton);
			this->Controls->Add(this->bitpSlicing);
			this->Controls->Add(this->graySlicingButton);
			this->Controls->Add(this->powerTransformButton);
			this->Controls->Add(this->logInverseButton);
			this->Controls->Add(this->logTransformButton);
			this->Controls->Add(this->stretchingButton);
			this->Controls->Add(this->brighteningButton);
			this->Controls->Add(this->imgZoomButton);
			this->Controls->Add(this->imgFlipButton);
			this->Controls->Add(this->imgRotateButton);
			this->Controls->Add(this->imgMoveButton);
			this->Controls->Add(this->operXORButton);
			this->Controls->Add(this->operORButton);
			this->Controls->Add(this->operANDButton);
			this->Controls->Add(this->operNOTButton);
			this->Controls->Add(this->showButton);
			this->Controls->Add(this->imgSubstButton);
			this->Controls->Add(this->imgAddButton);
			this->Controls->Add(this->toGraysButton);
			this->Controls->Add(this->toNegativeButton);
			this->Controls->Add(this->openBMPButton);
			this->Controls->Add(this->openPGMButton);
			this->Controls->Add(this->openPBMButton);
			this->Controls->Add(this->openPPMButton);
			this->Controls->Add(this->menuStrip);
			this->MaximumSize = System::Drawing::Size(800, 600);
			this->MinimumSize = System::Drawing::Size(800, 600);
			this->Name = L"GUIProgram";
			this->Text = L"GUIProgram";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private:
		Void hideAllButton()
		{
			this->toNegativeButton->Visible = false;
			this->toGraysButton->Visible = false;
			this->imgAddButton->Visible = false;
			this->imgSubstButton->Visible = false;
			this->showButton->Visible = false;
			this->operNOTButton->Visible = false;
			this->operANDButton->Visible = false;
			this->operORButton->Visible = false;
			this->operXORButton->Visible = false;
			this->imgMoveButton->Visible = false;
			this->imgRotateButton->Visible = false;
			this->imgFlipButton->Visible = false;
			this->imgZoomButton->Visible = false;
			this->brighteningButton->Visible = false;
			this->stretchingButton->Visible = false;
			this->logTransformButton->Visible = false;
			this->logInverseButton->Visible = false;
			this->powerTransformButton->Visible = false;
			this->graySlicingButton->Visible = false;
			this->bitpSlicing->Visible = false;
			this->histEqButton->Visible = false;
			this->histoSpecButton->Visible = false;
			this->convolutionButton->Visible = false;
			this->blurButton->Visible = false;
			this->sharpeningButton->Visible = false;
			this->noiseButton->Visible = false;
		}

		Void firstMenuButton_Click(Object^ sender, EventArgs^ e)
		{
			hideAllButton();

			this->toNegativeButton->Visible = true;
			this->toGraysButton->Visible = true;
			this->imgAddButton->Visible = true;
			this->imgSubstButton->Visible = true;
			this->convolutionButton->Visible = true;
			this->blurButton->Visible = true;
			this->sharpeningButton->Visible = true;
			this->noiseButton->Visible = true;
		}

		Void secondMenuButton_Click(Object^ sender, EventArgs^ e)
		{
			hideAllButton();

			this->operNOTButton->Visible = true;
			this->operANDButton->Visible = true;
			this->operORButton->Visible = true;
			this->operXORButton->Visible = true;
			this->imgMoveButton->Visible = true;
			this->imgRotateButton->Visible = true;
			this->imgFlipButton->Visible = true;
			this->imgZoomButton->Visible = true;
		}

		Void thirdMenuButton_Click(Object^ sender, EventArgs^ e)
		{
			hideAllButton();

			this->brighteningButton->Visible = true;
			this->stretchingButton->Visible = true;
			this->logTransformButton->Visible = true;
			this->logInverseButton->Visible = true;
			this->powerTransformButton->Visible = true;
			this->graySlicingButton->Visible = true;
			this->bitpSlicing->Visible = true;
			this->histEqButton->Visible = true;
			this->histoSpecButton->Visible = true;
		}

		Void showButton_Click(Object^ sender, EventArgs^ e)
		{
			hideAllButton();
			//MiniPhotoshop3::PhotoViewer photoViewerWindow;
			//photoViewerWindow.ShowDialog();
			//this->Show();
		}
	};
}
