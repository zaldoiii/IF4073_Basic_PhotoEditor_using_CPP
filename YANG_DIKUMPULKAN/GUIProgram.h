#pragma once

#include "source/format.cpp"
#include "source/function.cpp"
#include <string>

namespace MiniPhotoshop3
{
	using namespace System;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;
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

	public: 
		Custom::Image* defaultImg;
		Custom::Image* dynamicImg;
		Custom::Image* renderedImg;
		Custom::Image* secondaryImg;
		Custom::Image* combinedImg;

	private:
		int m;
		int n;
		int moveCount, zoomLevel, formatStatus;
		bool isImageShowing, isMenuShowing;

		   //this->defaultImg = new Custom::Image();
		   //this->dynamicImg = new Custom::Image();
		   //this->translatedImg = new Custom::Image();
			//this->secondaryImg = new Custom::Image();
			//this->openPPMButton->Click += gcnew System::EventHandler(this, &GUIProgram::openPPMButton_Click);
		   //this->imgXYFlipButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgXYFlipButton_Click);
			//this->toEditorButton->Click += gcnew System::EventHandler(this, &GUIProgram::toEditorButton_Click);
			//this->discardButton->Click += gcnew System::EventHandler(this, &GUIProgram::discardButton_Click);
			//this->toNegativeButton->Click += gcnew System::EventHandler(this, &GUIProgram::toNegativeButton_Click);
			//this->toGraysButton->Click += gcnew System::EventHandler(this, &GUIProgram::toGraysButton_Click);
			//this->imgMoveButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgMoveButton_Click);
			//this->imgVertFlipButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgVertFlipButton_Click);
			//this->brighteningButton->Click += gcnew System::EventHandler(this, &GUIProgram::brighteningButton_Click);
			//this->logTransformButton->Click += gcnew System::EventHandler(this, &GUIProgram::logTransformButton_Click);
			//this->imgPOFFlipButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgPOFFlipButton_Click);
		   //this->inverseLogButton->Click += gcnew System::EventHandler(this, &GUIProgram::inverseLogButton_Click);
			//this->powerTransformButton->Click += gcnew System::EventHandler(this, &GUIProgram::powerTransformButton_Click);
			//this->imgHorFlipButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgHorFlipButton_Click);
			//this->m = 0;
			//this->n = 0;
			//this->moveCount = 0;

			//this->isImageShowing = true;
			//this->isMenuShowing = !this->isImageShowing;

	private: System::Windows::Forms::OpenFileDialog^ dialog;
	private: System::Windows::Forms::SaveFileDialog^ saveDialog;

	private: System::Windows::Forms::Button^ openPPMButton;
	private: System::Windows::Forms::Button^ openPBMButton;
	private: System::Windows::Forms::Button^ openPGMButton;
	private: System::Windows::Forms::Button^ openBMPButton;

	private: System::Windows::Forms::Button^ toNegativeButton;
	private: System::Windows::Forms::Button^ toGraysButton;
	private: System::Windows::Forms::Button^ imgAddButton;
	private: System::Windows::Forms::Button^ imgSubstButton;
	private: System::Windows::Forms::Button^ imgMoveButton;

	private: System::Windows::Forms::Button^ operNOTButton;
	private: System::Windows::Forms::Button^ operANDButton;
	private: System::Windows::Forms::Button^ operORButton;
	private: System::Windows::Forms::Button^ operXORButton;

	private: System::Windows::Forms::Button^ imgCWButton;
	private: System::Windows::Forms::Button^ imgCCWButton;
	private: System::Windows::Forms::Button^ imgZoomInButton;
	private: System::Windows::Forms::Button^ imgZoomOutButton;
	private: System::Windows::Forms::Button^ imgVertFlipButton;
	private: System::Windows::Forms::Button^ imgHorFlipButton;
	private: System::Windows::Forms::Button^ imgPOFFlipButton;
	private: System::Windows::Forms::Button^ imgXYFlipButton;

	private: System::Windows::Forms::Button^ abrighteningButton;
	private: System::Windows::Forms::Button^ gBrighteningButton;
	private: System::Windows::Forms::ComboBox^ aBrightnessFactor;
	private: System::Windows::Forms::ComboBox^ gBrightnessFactor;

	private: System::Windows::Forms::Button^ logTransformButton;
	private: System::Windows::Forms::Button^ inverseLogButton;
	private: System::Windows::Forms::Button^ powerTransformButton;

	private: System::Windows::Forms::PictureBox^ pictureBox;
	private: System::Windows::Forms::Label^ logDebug;
	private: System::Windows::Forms::Button^ discardButton;
	private: System::Windows::Forms::Button^ showHistogramButton;

	private: System::Windows::Forms::Button^ toEditorButton;
	private: System::Windows::Forms::Button^ saveTempButton;

	private: System::Windows::Forms::ComboBox^ logValue;
	private: System::Windows::Forms::ComboBox^ inverseLogValue;
	private: System::Windows::Forms::ComboBox^ powerValue;


	private: System::Windows::Forms::ComboBox^ xGeserValue;
	private: System::Windows::Forms::ComboBox^ yGeserValue;
	private: System::Windows::Forms::Label^ xLabel;
	private: System::Windows::Forms::Label^ yLabel;

	private: System::Windows::Forms::Button^ preserveSlicingButton;
	private: System::Windows::Forms::Button^ discardSlicingButton;
	private: System::Windows::Forms::Button^ histEqButton;
	private: System::Windows::Forms::Button^ contrastStretchingButton;
	private: System::Windows::Forms::TextBox^ elemen00;
	private: System::Windows::Forms::TextBox^ elemen01;
	private: System::Windows::Forms::TextBox^ elemen02;
	private: System::Windows::Forms::TextBox^ elemen10;
	private: System::Windows::Forms::TextBox^ elemen11;
	private: System::Windows::Forms::TextBox^ elemen12;
	private: System::Windows::Forms::TextBox^ elemen20;
	private: System::Windows::Forms::TextBox^ elemen21;
	private: System::Windows::Forms::TextBox^ elemen22;

	private: System::Windows::Forms::Button^ convoluteButton;
	private: System::Windows::Forms::Button^ histSpecificButton;

	private: System::Windows::Forms::ComboBox^ widthValue;
	private: System::Windows::Forms::ComboBox^ heightValue;
	private: System::Windows::Forms::Label^ widthLabel;
	private: System::Windows::Forms::Label^ heightLabel;

	private: System::Windows::Forms::Button^ meanFilterButton;
	private: System::Windows::Forms::Button^ medianFilterButton;
	private: System::Windows::Forms::Button^ highPassButton;
	private: System::Windows::Forms::Button^ unsharpButton;
	private: System::Windows::Forms::Button^ highBoostButton;
	private: System::Windows::Forms::Button^ gaussianButton;

	private: System::Windows::Forms::PictureBox^ rHistogramViewer;
	private: System::Windows::Forms::PictureBox^ gHistogramViewer;
	private: System::Windows::Forms::PictureBox^ bHistogramViewer;
	private: System::Windows::Forms::ComboBox^ bitSlicingValue;
	private: System::Windows::Forms::Button^ bitPlaneButton;

	private:
		System::ComponentModel::Container^ components;

		void InitializeComponent(void)
		{
			this->defaultImg = new Custom::Image();
			this->dynamicImg = new Custom::Image();
			this->renderedImg = new Custom::Image();
			this->secondaryImg = new Custom::Image();
			this->combinedImg = new Custom::Image();

			this->m = 0;
			this->n = 0;
			this->moveCount = 0;
			this->zoomLevel = 0;
			this->formatStatus = 0;

			this->dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openPPMButton = (gcnew System::Windows::Forms::Button());
			this->openPBMButton = (gcnew System::Windows::Forms::Button());
			this->openPGMButton = (gcnew System::Windows::Forms::Button());
			this->openBMPButton = (gcnew System::Windows::Forms::Button());
			this->toEditorButton = (gcnew System::Windows::Forms::Button());
			this->saveTempButton = (gcnew System::Windows::Forms::Button());
			this->showHistogramButton = (gcnew System::Windows::Forms::Button());
			this->discardButton = (gcnew System::Windows::Forms::Button());
			this->toNegativeButton = (gcnew System::Windows::Forms::Button());
			this->toGraysButton = (gcnew System::Windows::Forms::Button());
			this->imgAddButton = (gcnew System::Windows::Forms::Button());
			this->imgSubstButton = (gcnew System::Windows::Forms::Button());
			this->operNOTButton = (gcnew System::Windows::Forms::Button());
			this->operANDButton = (gcnew System::Windows::Forms::Button());
			this->operORButton = (gcnew System::Windows::Forms::Button());
			this->operXORButton = (gcnew System::Windows::Forms::Button());
			this->imgMoveButton = (gcnew System::Windows::Forms::Button());
			this->imgCWButton = (gcnew System::Windows::Forms::Button());
			this->imgCCWButton = (gcnew System::Windows::Forms::Button());
			this->imgVertFlipButton = (gcnew System::Windows::Forms::Button());
			this->imgZoomInButton = (gcnew System::Windows::Forms::Button());
			this->abrighteningButton = (gcnew System::Windows::Forms::Button());
			this->aBrightnessFactor = (gcnew System::Windows::Forms::ComboBox());
			this->gBrighteningButton = (gcnew System::Windows::Forms::Button());
			this->gBrightnessFactor = (gcnew System::Windows::Forms::ComboBox());
			this->logTransformButton = (gcnew System::Windows::Forms::Button());
			this->inverseLogButton = (gcnew System::Windows::Forms::Button());
			this->powerTransformButton = (gcnew System::Windows::Forms::Button());
			this->logDebug = (gcnew System::Windows::Forms::Label());
			this->imgZoomOutButton = (gcnew System::Windows::Forms::Button());
			this->imgHorFlipButton = (gcnew System::Windows::Forms::Button());
			this->imgPOFFlipButton = (gcnew System::Windows::Forms::Button());
			this->imgXYFlipButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->logValue = (gcnew System::Windows::Forms::ComboBox());
			this->inverseLogValue = (gcnew System::Windows::Forms::ComboBox());
			this->powerValue = (gcnew System::Windows::Forms::ComboBox());
			this->xGeserValue = (gcnew System::Windows::Forms::ComboBox());
			this->yGeserValue = (gcnew System::Windows::Forms::ComboBox());
			this->xLabel = (gcnew System::Windows::Forms::Label());
			this->yLabel = (gcnew System::Windows::Forms::Label());
			this->preserveSlicingButton = (gcnew System::Windows::Forms::Button());
			this->discardSlicingButton = (gcnew System::Windows::Forms::Button());
			this->histEqButton = (gcnew System::Windows::Forms::Button());
			this->histSpecificButton = (gcnew System::Windows::Forms::Button());
			this->contrastStretchingButton = (gcnew System::Windows::Forms::Button());
			this->elemen00 = (gcnew System::Windows::Forms::TextBox());
			this->elemen01 = (gcnew System::Windows::Forms::TextBox());
			this->elemen02 = (gcnew System::Windows::Forms::TextBox());
			this->elemen10 = (gcnew System::Windows::Forms::TextBox());
			this->elemen11 = (gcnew System::Windows::Forms::TextBox());
			this->elemen12 = (gcnew System::Windows::Forms::TextBox());
			this->elemen20 = (gcnew System::Windows::Forms::TextBox());
			this->elemen21 = (gcnew System::Windows::Forms::TextBox());
			this->elemen22 = (gcnew System::Windows::Forms::TextBox());
			this->convoluteButton = (gcnew System::Windows::Forms::Button());
			this->widthValue = (gcnew System::Windows::Forms::ComboBox());
			this->heightValue = (gcnew System::Windows::Forms::ComboBox());
			this->widthLabel = (gcnew System::Windows::Forms::Label());
			this->heightLabel = (gcnew System::Windows::Forms::Label());
			this->meanFilterButton = (gcnew System::Windows::Forms::Button());
			this->medianFilterButton = (gcnew System::Windows::Forms::Button());
			this->highPassButton = (gcnew System::Windows::Forms::Button());
			this->unsharpButton = (gcnew System::Windows::Forms::Button());
			this->highBoostButton = (gcnew System::Windows::Forms::Button());
			this->gaussianButton = (gcnew System::Windows::Forms::Button());
			this->rHistogramViewer = (gcnew System::Windows::Forms::PictureBox());
			this->gHistogramViewer = (gcnew System::Windows::Forms::PictureBox());
			this->bHistogramViewer = (gcnew System::Windows::Forms::PictureBox());
			this->bitSlicingValue = (gcnew System::Windows::Forms::ComboBox());
			this->bitPlaneButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rHistogramViewer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gHistogramViewer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bHistogramViewer))->BeginInit();
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
			this->openPPMButton->Click += gcnew System::EventHandler(this, &GUIProgram::openPPMButton_Click);
			// 
			// openPBMButton
			// 
			this->openPBMButton->Location = System::Drawing::Point(0, 56);
			this->openPBMButton->Name = L"openPBMButton";
			this->openPBMButton->Size = System::Drawing::Size(80, 23);
			this->openPBMButton->TabIndex = 4;
			this->openPBMButton->Text = L"Open PBM";
			this->openPBMButton->UseVisualStyleBackColor = true;
			// 
			// openPGMButton
			// 
			this->openPGMButton->Location = System::Drawing::Point(0, 27);
			this->openPGMButton->Name = L"openPGMButton";
			this->openPGMButton->Size = System::Drawing::Size(80, 23);
			this->openPGMButton->TabIndex = 5;
			this->openPGMButton->Text = L"Open PGM";
			this->openPGMButton->UseVisualStyleBackColor = true;
			this->openPGMButton->Click += gcnew System::EventHandler(this, &GUIProgram::openPGMButton_Click);
			// 
			// openBMPButton
			// 
			this->openBMPButton->Location = System::Drawing::Point(0, 85);
			this->openBMPButton->Name = L"openBMPButton";
			this->openBMPButton->Size = System::Drawing::Size(80, 23);
			this->openBMPButton->TabIndex = 6;
			this->openBMPButton->Text = L"Open BMP";
			this->openBMPButton->UseVisualStyleBackColor = true;
			this->openBMPButton->Click += gcnew System::EventHandler(this, &GUIProgram::openBMPButton_Click);
			// 
			// toEditorButton
			// 
			this->toEditorButton->Location = System::Drawing::Point(0, 131);
			this->toEditorButton->Name = L"toEditorButton";
			this->toEditorButton->Size = System::Drawing::Size(80, 40);
			this->toEditorButton->TabIndex = 46;
			this->toEditorButton->Text = L"Toggle Image/Editor";
			this->toEditorButton->Visible = false;
			this->toEditorButton->Click += gcnew System::EventHandler(this, &GUIProgram::toEditorButton_Click);
			// 
			// saveTempButton
			// 
			this->saveTempButton->Location = System::Drawing::Point(86, 0);
			this->saveTempButton->Name = L"saveTempButton";
			this->saveTempButton->Size = System::Drawing::Size(80, 23);
			this->saveTempButton->TabIndex = 47;
			this->saveTempButton->Text = L"Save as ...";
			this->saveTempButton->UseVisualStyleBackColor = true;
			this->saveTempButton->Visible = false;
			this->saveTempButton->Click += gcnew System::EventHandler(this, &GUIProgram::saveTempButton_Click);
			// 
			// showHistogramButton
			// 
			this->showHistogramButton->Location = System::Drawing::Point(0, 221);
			this->showHistogramButton->Name = L"showHistogramButton";
			this->showHistogramButton->Size = System::Drawing::Size(80, 37);
			this->showHistogramButton->TabIndex = 39;
			this->showHistogramButton->Text = L"Show Histogram";
			this->showHistogramButton->UseVisualStyleBackColor = true;
			this->showHistogramButton->Visible = false;
			this->showHistogramButton->Click += gcnew System::EventHandler(this, &GUIProgram::showHistogramButton_Click);
			// 
			// discardButton
			// 
			this->discardButton->Location = System::Drawing::Point(0, 177);
			this->discardButton->Name = L"discardButton";
			this->discardButton->Size = System::Drawing::Size(80, 38);
			this->discardButton->TabIndex = 38;
			this->discardButton->Text = L"Discard Changes";
			this->discardButton->UseVisualStyleBackColor = true;
			this->discardButton->Visible = false;
			this->discardButton->Click += gcnew System::EventHandler(this, &GUIProgram::discardButton_Click);
			// 
			// toNegativeButton
			// 
			this->toNegativeButton->Location = System::Drawing::Point(331, 10);
			this->toNegativeButton->Name = L"toNegativeButton";
			this->toNegativeButton->Size = System::Drawing::Size(86, 23);
			this->toNegativeButton->TabIndex = 7;
			this->toNegativeButton->Text = L"Negative Color";
			this->toNegativeButton->UseVisualStyleBackColor = true;
			this->toNegativeButton->Visible = false;
			this->toNegativeButton->Click += gcnew System::EventHandler(this, &GUIProgram::toNegativeButton_Click);
			// 
			// toGraysButton
			// 
			this->toGraysButton->Location = System::Drawing::Point(423, 10);
			this->toGraysButton->Name = L"toGraysButton";
			this->toGraysButton->Size = System::Drawing::Size(86, 23);
			this->toGraysButton->TabIndex = 8;
			this->toGraysButton->Text = L"Grayscale";
			this->toGraysButton->UseVisualStyleBackColor = true;
			this->toGraysButton->Visible = false;
			this->toGraysButton->Click += gcnew System::EventHandler(this, &GUIProgram::toGraysButton_Click);
			// 
			// imgAddButton
			// 
			this->imgAddButton->Location = System::Drawing::Point(331, 48);
			this->imgAddButton->Name = L"imgAddButton";
			this->imgAddButton->Size = System::Drawing::Size(86, 23);
			this->imgAddButton->TabIndex = 9;
			this->imgAddButton->Text = L"Addition";
			this->imgAddButton->UseVisualStyleBackColor = true;
			this->imgAddButton->Visible = false;
			this->imgAddButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgAddButton_Click);
			// 
			// imgSubstButton
			// 
			this->imgSubstButton->Location = System::Drawing::Point(423, 48);
			this->imgSubstButton->Name = L"imgSubstButton";
			this->imgSubstButton->Size = System::Drawing::Size(86, 23);
			this->imgSubstButton->TabIndex = 10;
			this->imgSubstButton->Text = L"Subtraction";
			this->imgSubstButton->UseVisualStyleBackColor = true;
			this->imgSubstButton->Visible = false;
			this->imgSubstButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgSubstButton_Click);
			// 
			// operNOTButton
			// 
			this->operNOTButton->Location = System::Drawing::Point(331, 123);
			this->operNOTButton->Name = L"operNOTButton";
			this->operNOTButton->Size = System::Drawing::Size(86, 23);
			this->operNOTButton->TabIndex = 12;
			this->operNOTButton->Text = L"NOT";
			this->operNOTButton->UseVisualStyleBackColor = true;
			this->operNOTButton->Visible = false;
			this->operNOTButton->Click += gcnew System::EventHandler(this, &GUIProgram::operNOTButton_Click);
			// 
			// operANDButton
			// 
			this->operANDButton->Location = System::Drawing::Point(331, 85);
			this->operANDButton->Name = L"operANDButton";
			this->operANDButton->Size = System::Drawing::Size(86, 23);
			this->operANDButton->TabIndex = 13;
			this->operANDButton->Text = L"AND";
			this->operANDButton->UseVisualStyleBackColor = true;
			this->operANDButton->Visible = false;
			this->operANDButton->Click += gcnew System::EventHandler(this, &GUIProgram::operANDButton_Click);
			// 
			// operORButton
			// 
			this->operORButton->Location = System::Drawing::Point(423, 85);
			this->operORButton->Name = L"operORButton";
			this->operORButton->Size = System::Drawing::Size(86, 23);
			this->operORButton->TabIndex = 14;
			this->operORButton->Text = L"OR";
			this->operORButton->UseVisualStyleBackColor = true;
			this->operORButton->Visible = false;
			this->operORButton->Click += gcnew System::EventHandler(this, &GUIProgram::operORButton_Click);
			// 
			// operXORButton
			// 
			this->operXORButton->Location = System::Drawing::Point(423, 123);
			this->operXORButton->Name = L"operXORButton";
			this->operXORButton->Size = System::Drawing::Size(86, 23);
			this->operXORButton->TabIndex = 15;
			this->operXORButton->Text = L"XOR";
			this->operXORButton->UseVisualStyleBackColor = true;
			this->operXORButton->Visible = false;
			this->operXORButton->Click += gcnew System::EventHandler(this, &GUIProgram::operXORButton_Click);
			// 
			// imgMoveButton
			// 
			this->imgMoveButton->Location = System::Drawing::Point(354, 275);
			this->imgMoveButton->Name = L"imgMoveButton";
			this->imgMoveButton->Size = System::Drawing::Size(128, 23);
			this->imgMoveButton->TabIndex = 16;
			this->imgMoveButton->Text = L"Move";
			this->imgMoveButton->UseVisualStyleBackColor = true;
			this->imgMoveButton->Visible = false;
			this->imgMoveButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgMoveButton_Click);
			// 
			// imgCWButton
			// 
			this->imgCWButton->Location = System::Drawing::Point(331, 159);
			this->imgCWButton->Name = L"imgCWButton";
			this->imgCWButton->Size = System::Drawing::Size(86, 36);
			this->imgCWButton->TabIndex = 17;
			this->imgCWButton->Text = L"90 CW Rotate";
			this->imgCWButton->UseVisualStyleBackColor = true;
			this->imgCWButton->Visible = false;
			this->imgCWButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgCWButton_Click);
			// 
			// imgCCWButton
			// 
			this->imgCCWButton->Location = System::Drawing::Point(423, 159);
			this->imgCCWButton->Name = L"imgCCWButton";
			this->imgCCWButton->Size = System::Drawing::Size(86, 36);
			this->imgCCWButton->TabIndex = 52;
			this->imgCCWButton->Text = L"90 CCW Rotate";
			this->imgCCWButton->UseVisualStyleBackColor = true;
			this->imgCCWButton->Visible = false;
			this->imgCCWButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgCCWButton_Click);
			// 
			// imgVertFlipButton
			// 
			this->imgVertFlipButton->Location = System::Drawing::Point(270, 383);
			this->imgVertFlipButton->Name = L"imgVertFlipButton";
			this->imgVertFlipButton->Size = System::Drawing::Size(64, 36);
			this->imgVertFlipButton->TabIndex = 18;
			this->imgVertFlipButton->Text = L"Vertical Flip";
			this->imgVertFlipButton->UseVisualStyleBackColor = true;
			this->imgVertFlipButton->Visible = false;
			this->imgVertFlipButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgVertFlipButton_Click);
			// 
			// imgZoomInButton
			// 
			this->imgZoomInButton->Location = System::Drawing::Point(331, 209);
			this->imgZoomInButton->Name = L"imgZoomInButton";
			this->imgZoomInButton->Size = System::Drawing::Size(86, 23);
			this->imgZoomInButton->TabIndex = 19;
			this->imgZoomInButton->Text = L"Zoom In";
			this->imgZoomInButton->UseVisualStyleBackColor = true;
			this->imgZoomInButton->Visible = false;
			this->imgZoomInButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgZoomInButton_Click);
			// 
			// abrighteningButton
			// 
			this->abrighteningButton->Location = System::Drawing::Point(200, 33);
			this->abrighteningButton->Name = L"abrighteningButton";
			this->abrighteningButton->Size = System::Drawing::Size(80, 35);
			this->abrighteningButton->TabIndex = 20;
			this->abrighteningButton->Text = L"Arithmetic Brightening";
			this->abrighteningButton->UseVisualStyleBackColor = true;
			this->abrighteningButton->Visible = false;
			this->abrighteningButton->Click += gcnew System::EventHandler(this, &GUIProgram::abrighteningButton_Click);
			// 
			// aBrightnessFactor
			// 
			this->aBrightnessFactor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->aBrightnessFactor->FormattingEnabled = true;
			this->aBrightnessFactor->Items->AddRange(gcnew cli::array< System::Object^  >(11) {
				L"+255", L"+100", L"+50", L"+25", L"+10",
					L"0", L"-10", L"-25", L"-50", L"-100", L"-255"
			});
			this->aBrightnessFactor->Location = System::Drawing::Point(200, 11);
			this->aBrightnessFactor->Name = L"aBrightnessFactor";
			this->aBrightnessFactor->Size = System::Drawing::Size(80, 21);
			this->aBrightnessFactor->TabIndex = 69;
			this->aBrightnessFactor->Visible = false;
			// 
			// gBrighteningButton
			// 
			this->gBrighteningButton->Location = System::Drawing::Point(200, 91);
			this->gBrighteningButton->Name = L"gBrighteningButton";
			this->gBrighteningButton->Size = System::Drawing::Size(80, 35);
			this->gBrighteningButton->TabIndex = 70;
			this->gBrighteningButton->Text = L"Geometric Brightening";
			this->gBrighteningButton->UseVisualStyleBackColor = true;
			this->gBrighteningButton->Visible = false;
			this->gBrighteningButton->Click += gcnew System::EventHandler(this, &GUIProgram::gBrighteningButton_Click);
			// 
			// gBrightnessFactor
			// 
			this->gBrightnessFactor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->gBrightnessFactor->FormattingEnabled = true;
			this->gBrightnessFactor->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"1.5", L"1.25", L"1", L"0.75", L"0.5",
					L"0.25", L"0"
			});
			this->gBrightnessFactor->Location = System::Drawing::Point(200, 69);
			this->gBrightnessFactor->Name = L"gBrightnessFactor";
			this->gBrightnessFactor->Size = System::Drawing::Size(80, 21);
			this->gBrightnessFactor->TabIndex = 60;
			this->gBrightnessFactor->Visible = false;
			// 
			// logTransformButton
			// 
			this->logTransformButton->Location = System::Drawing::Point(200, 177);
			this->logTransformButton->Name = L"logTransformButton";
			this->logTransformButton->Size = System::Drawing::Size(80, 36);
			this->logTransformButton->TabIndex = 22;
			this->logTransformButton->Text = L"Log Transform";
			this->logTransformButton->UseVisualStyleBackColor = true;
			this->logTransformButton->Visible = false;
			this->logTransformButton->Click += gcnew System::EventHandler(this, &GUIProgram::logTransformButton_Click);
			// 
			// inverseLogButton
			// 
			this->inverseLogButton->Location = System::Drawing::Point(200, 250);
			this->inverseLogButton->Name = L"inverseLogButton";
			this->inverseLogButton->Size = System::Drawing::Size(80, 37);
			this->inverseLogButton->TabIndex = 23;
			this->inverseLogButton->Text = L"Inverse Log Transform";
			this->inverseLogButton->UseVisualStyleBackColor = true;
			this->inverseLogButton->Visible = false;
			this->inverseLogButton->Click += gcnew System::EventHandler(this, &GUIProgram::inverseLogButton_Click);
			// 
			// powerTransformButton
			// 
			this->powerTransformButton->Location = System::Drawing::Point(200, 322);
			this->powerTransformButton->Name = L"powerTransformButton";
			this->powerTransformButton->Size = System::Drawing::Size(95, 29);
			this->powerTransformButton->TabIndex = 24;
			this->powerTransformButton->Text = L"Power Transform";
			this->powerTransformButton->UseVisualStyleBackColor = true;
			this->powerTransformButton->Visible = false;
			this->powerTransformButton->Click += gcnew System::EventHandler(this, &GUIProgram::powerTransformButton_Click);
			// 
			// logDebug
			// 
			this->logDebug->AutoSize = true;
			this->logDebug->Location = System::Drawing::Point(197, 425);
			this->logDebug->Name = L"logDebug";
			this->logDebug->Size = System::Drawing::Size(0, 13);
			this->logDebug->TabIndex = 37;
			// 
			// imgZoomOutButton
			// 
			this->imgZoomOutButton->Location = System::Drawing::Point(423, 209);
			this->imgZoomOutButton->Name = L"imgZoomOutButton";
			this->imgZoomOutButton->Size = System::Drawing::Size(86, 23);
			this->imgZoomOutButton->TabIndex = 53;
			this->imgZoomOutButton->Text = L"Zoom Out";
			this->imgZoomOutButton->UseVisualStyleBackColor = true;
			this->imgZoomOutButton->Visible = false;
			this->imgZoomOutButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgZoomOutButton_Click);
			// 
			// imgHorFlipButton
			// 
			this->imgHorFlipButton->Location = System::Drawing::Point(200, 383);
			this->imgHorFlipButton->Name = L"imgHorFlipButton";
			this->imgHorFlipButton->Size = System::Drawing::Size(64, 36);
			this->imgHorFlipButton->TabIndex = 56;
			this->imgHorFlipButton->Text = L"Horizontal Flip";
			this->imgHorFlipButton->UseVisualStyleBackColor = true;
			this->imgHorFlipButton->Visible = false;
			this->imgHorFlipButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgHorFlipButton_Click);
			// 
			// imgPOFFlipButton
			// 
			this->imgPOFFlipButton->Location = System::Drawing::Point(200, 425);
			this->imgPOFFlipButton->Name = L"imgPOFFlipButton";
			this->imgPOFFlipButton->Size = System::Drawing::Size(64, 23);
			this->imgPOFFlipButton->TabIndex = 57;
			this->imgPOFFlipButton->Text = L"POF Flip";
			this->imgPOFFlipButton->UseVisualStyleBackColor = true;
			this->imgPOFFlipButton->Visible = false;
			this->imgPOFFlipButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgPOFFlipButton_Click);
			// 
			// imgXYFlipButton
			// 
			this->imgXYFlipButton->Location = System::Drawing::Point(270, 425);
			this->imgXYFlipButton->Name = L"imgXYFlipButton";
			this->imgXYFlipButton->Size = System::Drawing::Size(64, 23);
			this->imgXYFlipButton->TabIndex = 58;
			this->imgXYFlipButton->Text = L"XY Flip";
			this->imgXYFlipButton->UseVisualStyleBackColor = true;
			this->imgXYFlipButton->Visible = false;
			this->imgXYFlipButton->Click += gcnew System::EventHandler(this, &GUIProgram::imgXYFlipButton_Click);
			// 
			// pictureBox
			// 
			this->pictureBox->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->pictureBox->Location = System::Drawing::Point(172, 0);
			this->pictureBox->MaximumSize = System::Drawing::Size(1920, 1080);
			this->pictureBox->MinimumSize = System::Drawing::Size(1, 1);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(619, 561);
			this->pictureBox->TabIndex = 36;
			this->pictureBox->TabStop = false;
			// 
			// logValue
			// 
			this->logValue->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->logValue->FormattingEnabled = true;
			this->logValue->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"1.2", L"1", L"0.8", L"0.6", L"0.4", L"0.2" });
			this->logValue->Location = System::Drawing::Point(200, 155);
			this->logValue->Name = L"logValue";
			this->logValue->Size = System::Drawing::Size(80, 21);
			this->logValue->TabIndex = 61;
			this->logValue->Visible = false;
			// 
			// inverseLogValue
			// 
			this->inverseLogValue->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->inverseLogValue->FormattingEnabled = true;
			this->inverseLogValue->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"1.5", L"1.25", L"1", L"0.75", L"0.5", L"0.25" });
			this->inverseLogValue->Location = System::Drawing::Point(200, 228);
			this->inverseLogValue->Name = L"inverseLogValue";
			this->inverseLogValue->Size = System::Drawing::Size(80, 21);
			this->inverseLogValue->TabIndex = 62;
			this->inverseLogValue->Visible = false;
			// 
			// powerValue
			// 
			this->powerValue->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->powerValue->FormattingEnabled = true;
			this->powerValue->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1.5", L"1.1", L"1", L"0.9", L"0.5" });
			this->powerValue->Location = System::Drawing::Point(200, 300);
			this->powerValue->Name = L"powerValue";
			this->powerValue->Size = System::Drawing::Size(95, 21);
			this->powerValue->TabIndex = 63;
			this->powerValue->Visible = false;
			// 
			// xGeserValue
			// 
			this->xGeserValue->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->xGeserValue->FormattingEnabled = true;
			this->xGeserValue->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"100", L"50", L"25", L"10", L"0", L"-10", L"-25",
					L"-50", L"-100"
			});
			this->xGeserValue->Location = System::Drawing::Point(375, 250);
			this->xGeserValue->Name = L"xGeserValue";
			this->xGeserValue->Size = System::Drawing::Size(42, 21);
			this->xGeserValue->TabIndex = 65;
			this->xGeserValue->Visible = false;
			// 
			// yGeserValue
			// 
			this->yGeserValue->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->yGeserValue->FormattingEnabled = true;
			this->yGeserValue->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"100", L"50", L"25", L"10", L"0", L"-10", L"-25",
					L"-50", L"-100"
			});
			this->yGeserValue->Location = System::Drawing::Point(440, 250);
			this->yGeserValue->Name = L"yGeserValue";
			this->yGeserValue->Size = System::Drawing::Size(42, 21);
			this->yGeserValue->TabIndex = 66;
			this->yGeserValue->Visible = false;
			// 
			// xLabel
			// 
			this->xLabel->AutoSize = true;
			this->xLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->xLabel->Location = System::Drawing::Point(354, 251);
			this->xLabel->Name = L"xLabel";
			this->xLabel->Size = System::Drawing::Size(20, 20);
			this->xLabel->TabIndex = 67;
			this->xLabel->Text = L"X";
			this->xLabel->Visible = false;
			// 
			// yLabel
			// 
			this->yLabel->AutoSize = true;
			this->yLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->yLabel->Location = System::Drawing::Point(419, 251);
			this->yLabel->Name = L"yLabel";
			this->yLabel->Size = System::Drawing::Size(20, 20);
			this->yLabel->TabIndex = 68;
			this->yLabel->Text = L"Y";
			this->yLabel->Visible = false;
			// 
			// preserveSlicingButton
			// 
			this->preserveSlicingButton->Location = System::Drawing::Point(588, 333);
			this->preserveSlicingButton->Name = L"preserveSlicingButton";
			this->preserveSlicingButton->Size = System::Drawing::Size(80, 50);
			this->preserveSlicingButton->TabIndex = 71;
			this->preserveSlicingButton->Text = L"Preserve Background Slicing";
			this->preserveSlicingButton->UseVisualStyleBackColor = true;
			this->preserveSlicingButton->Visible = false;
			this->preserveSlicingButton->Click += gcnew System::EventHandler(this, &GUIProgram::preserveSlicingButton_Click);
			// 
			// discardSlicingButton
			// 
			this->discardSlicingButton->Location = System::Drawing::Point(674, 333);
			this->discardSlicingButton->Name = L"discardSlicingButton";
			this->discardSlicingButton->Size = System::Drawing::Size(80, 50);
			this->discardSlicingButton->TabIndex = 72;
			this->discardSlicingButton->Text = L"Discard Background Slicing";
			this->discardSlicingButton->UseVisualStyleBackColor = true;
			this->discardSlicingButton->Visible = false;
			this->discardSlicingButton->Click += gcnew System::EventHandler(this, &GUIProgram::discardSlicingButton_Click);
			// 
			// histEqButton
			// 
			this->histEqButton->Location = System::Drawing::Point(588, 389);
			this->histEqButton->Name = L"histEqButton";
			this->histEqButton->Size = System::Drawing::Size(80, 37);
			this->histEqButton->TabIndex = 73;
			this->histEqButton->Text = L"Histogram Equalization";
			this->histEqButton->UseVisualStyleBackColor = true;
			this->histEqButton->Visible = false;
			this->histEqButton->Click += gcnew System::EventHandler(this, &GUIProgram::histEqButton_Click);
			// 
			// histSpecificButton
			// 
			this->histSpecificButton->Location = System::Drawing::Point(588, 432);
			this->histSpecificButton->Name = L"histSpecificButton";
			this->histSpecificButton->Size = System::Drawing::Size(166, 23);
			this->histSpecificButton->TabIndex = 85;
			this->histSpecificButton->Text = L"Histogram Specification";
			this->histSpecificButton->UseVisualStyleBackColor = true;
			this->histSpecificButton->Visible = false;
			// 
			// contrastStretchingButton
			// 
			this->contrastStretchingButton->Location = System::Drawing::Point(674, 389);
			this->contrastStretchingButton->Name = L"contrastStretchingButton";
			this->contrastStretchingButton->Size = System::Drawing::Size(80, 37);
			this->contrastStretchingButton->TabIndex = 74;
			this->contrastStretchingButton->Text = L"Contrast Stretching";
			this->contrastStretchingButton->UseVisualStyleBackColor = true;
			this->contrastStretchingButton->Visible = false;
			this->contrastStretchingButton->Click += gcnew System::EventHandler(this, &GUIProgram::contrastStretchingButton_Click);
			// 
			// elemen00
			// 
			this->elemen00->Location = System::Drawing::Point(588, 13);
			this->elemen00->MaxLength = 1;
			this->elemen00->Name = L"elemen00";
			this->elemen00->Size = System::Drawing::Size(25, 20);
			this->elemen00->TabIndex = 75;
			this->elemen00->Visible = false;
			// 
			// elemen01
			// 
			this->elemen01->Location = System::Drawing::Point(619, 13);
			this->elemen01->MaxLength = 1;
			this->elemen01->Name = L"elemen01";
			this->elemen01->Size = System::Drawing::Size(25, 20);
			this->elemen01->TabIndex = 76;
			this->elemen01->Visible = false;
			// 
			// elemen02
			// 
			this->elemen02->Location = System::Drawing::Point(650, 13);
			this->elemen02->MaxLength = 1;
			this->elemen02->Name = L"elemen02";
			this->elemen02->Size = System::Drawing::Size(25, 20);
			this->elemen02->TabIndex = 77;
			this->elemen02->Visible = false;
			// 
			// elemen10
			// 
			this->elemen10->Location = System::Drawing::Point(588, 39);
			this->elemen10->MaxLength = 1;
			this->elemen10->Name = L"elemen10";
			this->elemen10->Size = System::Drawing::Size(25, 20);
			this->elemen10->TabIndex = 78;
			this->elemen10->Visible = false;
			// 
			// elemen11
			// 
			this->elemen11->Location = System::Drawing::Point(619, 39);
			this->elemen11->MaxLength = 1;
			this->elemen11->Name = L"elemen11";
			this->elemen11->Size = System::Drawing::Size(25, 20);
			this->elemen11->TabIndex = 79;
			this->elemen11->Visible = false;
			// 
			// elemen12
			// 
			this->elemen12->Location = System::Drawing::Point(650, 39);
			this->elemen12->MaxLength = 1;
			this->elemen12->Name = L"elemen12";
			this->elemen12->Size = System::Drawing::Size(25, 20);
			this->elemen12->TabIndex = 80;
			this->elemen12->Visible = false;
			// 
			// elemen20
			// 
			this->elemen20->Location = System::Drawing::Point(588, 65);
			this->elemen20->MaxLength = 1;
			this->elemen20->Name = L"elemen20";
			this->elemen20->Size = System::Drawing::Size(25, 20);
			this->elemen20->TabIndex = 81;
			this->elemen20->Visible = false;
			// 
			// elemen21
			// 
			this->elemen21->Location = System::Drawing::Point(619, 65);
			this->elemen21->MaxLength = 1;
			this->elemen21->Name = L"elemen21";
			this->elemen21->Size = System::Drawing::Size(25, 20);
			this->elemen21->TabIndex = 82;
			this->elemen21->Visible = false;
			// 
			// elemen22
			// 
			this->elemen22->Location = System::Drawing::Point(650, 65);
			this->elemen22->MaxLength = 1;
			this->elemen22->Name = L"elemen22";
			this->elemen22->Size = System::Drawing::Size(25, 20);
			this->elemen22->TabIndex = 83;
			this->elemen22->Visible = false;
			// 
			// convoluteButton
			// 
			this->convoluteButton->Location = System::Drawing::Point(588, 91);
			this->convoluteButton->Name = L"convoluteButton";
			this->convoluteButton->Size = System::Drawing::Size(87, 23);
			this->convoluteButton->TabIndex = 84;
			this->convoluteButton->Text = L"Convolute";
			this->convoluteButton->UseVisualStyleBackColor = true;
			this->convoluteButton->Visible = false;
			// 
			// widthValue
			// 
			this->widthValue->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->widthValue->FormattingEnabled = true;
			this->widthValue->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"100", L"50", L"25", L"10", L"0", L"-10", L"-25",
					L"-50", L"-100"
			});
			this->widthValue->Location = System::Drawing::Point(691, 221);
			this->widthValue->Name = L"widthValue";
			this->widthValue->Size = System::Drawing::Size(54, 21);
			this->widthValue->TabIndex = 86;
			this->widthValue->Visible = false;
			// 
			// heightValue
			// 
			this->heightValue->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->heightValue->FormattingEnabled = true;
			this->heightValue->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"100", L"50", L"25", L"10", L"0", L"-10", L"-25",
					L"-50", L"-100"
			});
			this->heightValue->Location = System::Drawing::Point(588, 221);
			this->heightValue->Name = L"heightValue";
			this->heightValue->Size = System::Drawing::Size(56, 21);
			this->heightValue->TabIndex = 87;
			this->heightValue->Visible = false;
			// 
			// widthLabel
			// 
			this->widthLabel->AutoSize = true;
			this->widthLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->widthLabel->Location = System::Drawing::Point(546, 229);
			this->widthLabel->Name = L"widthLabel";
			this->widthLabel->Size = System::Drawing::Size(35, 13);
			this->widthLabel->TabIndex = 88;
			this->widthLabel->Text = L"Width";
			this->widthLabel->Visible = false;
			// 
			// heightLabel
			// 
			this->heightLabel->AutoSize = true;
			this->heightLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->heightLabel->Location = System::Drawing::Point(647, 229);
			this->heightLabel->Name = L"heightLabel";
			this->heightLabel->Size = System::Drawing::Size(38, 13);
			this->heightLabel->TabIndex = 89;
			this->heightLabel->Text = L"Height";
			this->heightLabel->Visible = false;
			// 
			// meanFilterButton
			// 
			this->meanFilterButton->Location = System::Drawing::Point(549, 248);
			this->meanFilterButton->Name = L"meanFilterButton";
			this->meanFilterButton->Size = System::Drawing::Size(95, 52);
			this->meanFilterButton->TabIndex = 90;
			this->meanFilterButton->Text = L"Image Blurring (Mean Filtering)";
			this->meanFilterButton->UseVisualStyleBackColor = true;
			this->meanFilterButton->Visible = false;
			// 
			// medianFilterButton
			// 
			this->medianFilterButton->Location = System::Drawing::Point(650, 248);
			this->medianFilterButton->Name = L"medianFilterButton";
			this->medianFilterButton->Size = System::Drawing::Size(95, 52);
			this->medianFilterButton->TabIndex = 91;
			this->medianFilterButton->Text = L"Noise Removal (Median Filtering)";
			this->medianFilterButton->UseVisualStyleBackColor = true;
			this->medianFilterButton->Visible = false;
			// 
			// highPassButton
			// 
			this->highPassButton->Location = System::Drawing::Point(407, 376);
			this->highPassButton->Name = L"highPassButton";
			this->highPassButton->Size = System::Drawing::Size(126, 23);
			this->highPassButton->TabIndex = 92;
			this->highPassButton->Text = L"High-Pass Sharpening";
			this->highPassButton->UseVisualStyleBackColor = true;
			this->highPassButton->Visible = false;
			// 
			// unsharpButton
			// 
			this->unsharpButton->Location = System::Drawing::Point(407, 405);
			this->unsharpButton->Name = L"unsharpButton";
			this->unsharpButton->Size = System::Drawing::Size(126, 23);
			this->unsharpButton->TabIndex = 93;
			this->unsharpButton->Text = L"Unsharp Masking";
			this->unsharpButton->UseVisualStyleBackColor = true;
			this->unsharpButton->Visible = false;
			// 
			// highBoostButton
			// 
			this->highBoostButton->Location = System::Drawing::Point(407, 434);
			this->highBoostButton->Name = L"highBoostButton";
			this->highBoostButton->Size = System::Drawing::Size(126, 23);
			this->highBoostButton->TabIndex = 94;
			this->highBoostButton->Text = L"Highboost Filter";
			this->highBoostButton->UseVisualStyleBackColor = true;
			this->highBoostButton->Visible = false;
			// 
			// gaussianButton
			// 
			this->gaussianButton->Location = System::Drawing::Point(407, 347);
			this->gaussianButton->Name = L"gaussianButton";
			this->gaussianButton->Size = System::Drawing::Size(126, 23);
			this->gaussianButton->TabIndex = 95;
			this->gaussianButton->Text = L"Gaussian Smoothing";
			this->gaussianButton->UseVisualStyleBackColor = true;
			this->gaussianButton->Visible = false;
			//this->gaussianButton->Click += gcnew System::EventHandler(this, &GUIProgram::gaussianButton_Click);
			// 
			// rhistogramViewer
			// 
			this->rHistogramViewer->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->rHistogramViewer->Location = System::Drawing::Point(182, 10);
			this->rHistogramViewer->Name = L"rHistogramViewer";
			this->rHistogramViewer->Size = System::Drawing::Size(256, 100);
			this->rHistogramViewer->TabIndex = 96;
			this->rHistogramViewer->TabStop = false;
			this->rHistogramViewer->Visible = false;
			// 
			// gHistogramViewer
			// 
			this->gHistogramViewer->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->gHistogramViewer->Location = System::Drawing::Point(182, 120);
			this->gHistogramViewer->Name = L"gHistogramViewer";
			this->gHistogramViewer->Size = System::Drawing::Size(256, 100);
			this->gHistogramViewer->TabIndex = 97;
			this->gHistogramViewer->TabStop = false;
			this->gHistogramViewer->Visible = false;
			// 
			// bHistogramViewer
			// 
			this->bHistogramViewer->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->bHistogramViewer->Location = System::Drawing::Point(182, 230);
			this->bHistogramViewer->Name = L"bHistogramViewer";
			this->bHistogramViewer->Size = System::Drawing::Size(256, 100);
			this->bHistogramViewer->TabIndex = 98;
			this->bHistogramViewer->TabStop = false;
			this->bHistogramViewer->Visible = false;
			// 
			// bitSlicingValue
			// 
			this->bitSlicingValue->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->bitSlicingValue->FormattingEnabled = true;
			this->bitSlicingValue->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7"
			});
			this->bitSlicingValue->Location = System::Drawing::Point(588, 141);
			this->bitSlicingValue->Name = L"bitSlicingValue";
			this->bitSlicingValue->Size = System::Drawing::Size(87, 21);
			this->bitSlicingValue->TabIndex = 99;
			this->bitSlicingValue->Visible = false;
			// 
			// bitPlaneButton
			// 
			this->bitPlaneButton->Location = System::Drawing::Point(588, 164);
			this->bitPlaneButton->Name = L"bitPlaneButton";
			this->bitPlaneButton->Size = System::Drawing::Size(87, 23);
			this->bitPlaneButton->TabIndex = 100;
			this->bitPlaneButton->Text = L"Bit-Plane Slicing";
			this->bitPlaneButton->UseVisualStyleBackColor = true;
			this->bitPlaneButton->Visible = false;
			this->bitPlaneButton->Click += gcnew System::EventHandler(this, &GUIProgram::bitPlaneButton_Click);
			// 
			// GUIProgram
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(792, 573);
			this->Controls->Add(this->bitPlaneButton);
			this->Controls->Add(this->bitSlicingValue);
			this->Controls->Add(this->bHistogramViewer);
			this->Controls->Add(this->gHistogramViewer);
			this->Controls->Add(this->rHistogramViewer);
			this->Controls->Add(this->gaussianButton);
			this->Controls->Add(this->highBoostButton);
			this->Controls->Add(this->unsharpButton);
			this->Controls->Add(this->highPassButton);
			this->Controls->Add(this->medianFilterButton);
			this->Controls->Add(this->meanFilterButton);
			this->Controls->Add(this->heightLabel);
			this->Controls->Add(this->widthLabel);
			this->Controls->Add(this->heightValue);
			this->Controls->Add(this->widthValue);
			this->Controls->Add(this->histSpecificButton);
			this->Controls->Add(this->convoluteButton);
			this->Controls->Add(this->elemen22);
			this->Controls->Add(this->elemen21);
			this->Controls->Add(this->elemen20);
			this->Controls->Add(this->elemen12);
			this->Controls->Add(this->elemen11);
			this->Controls->Add(this->elemen10);
			this->Controls->Add(this->elemen02);
			this->Controls->Add(this->elemen01);
			this->Controls->Add(this->elemen00);
			this->Controls->Add(this->contrastStretchingButton);
			this->Controls->Add(this->histEqButton);
			this->Controls->Add(this->discardSlicingButton);
			this->Controls->Add(this->preserveSlicingButton);
			this->Controls->Add(this->gBrighteningButton);
			this->Controls->Add(this->aBrightnessFactor);
			this->Controls->Add(this->yLabel);
			this->Controls->Add(this->xLabel);
			this->Controls->Add(this->yGeserValue);
			this->Controls->Add(this->xGeserValue);
			this->Controls->Add(this->powerValue);
			this->Controls->Add(this->inverseLogValue);
			this->Controls->Add(this->logValue);
			this->Controls->Add(this->gBrightnessFactor);
			this->Controls->Add(this->imgXYFlipButton);
			this->Controls->Add(this->imgPOFFlipButton);
			this->Controls->Add(this->imgHorFlipButton);
			this->Controls->Add(this->imgZoomOutButton);
			this->Controls->Add(this->imgCCWButton);
			this->Controls->Add(this->saveTempButton);
			this->Controls->Add(this->toEditorButton);
			this->Controls->Add(this->showHistogramButton);
			this->Controls->Add(this->discardButton);
			this->Controls->Add(this->logDebug);
			this->Controls->Add(this->powerTransformButton);
			this->Controls->Add(this->inverseLogButton);
			this->Controls->Add(this->logTransformButton);
			this->Controls->Add(this->abrighteningButton);
			this->Controls->Add(this->imgZoomInButton);
			this->Controls->Add(this->imgVertFlipButton);
			this->Controls->Add(this->imgCWButton);
			this->Controls->Add(this->imgMoveButton);
			this->Controls->Add(this->operXORButton);
			this->Controls->Add(this->operORButton);
			this->Controls->Add(this->operANDButton);
			this->Controls->Add(this->operNOTButton);
			this->Controls->Add(this->imgSubstButton);
			this->Controls->Add(this->imgAddButton);
			this->Controls->Add(this->toGraysButton);
			this->Controls->Add(this->toNegativeButton);
			this->Controls->Add(this->openBMPButton);
			this->Controls->Add(this->openPGMButton);
			this->Controls->Add(this->openPBMButton);
			this->Controls->Add(this->openPPMButton);
			this->Controls->Add(this->pictureBox);
			this->MaximumSize = System::Drawing::Size(1280, 720);
			this->MinimumSize = System::Drawing::Size(800, 600);
			this->Name = L"GUIProgram";
			this->Text = L"Basic Photo Editor v135.17 by -Irfan_Dandi_Anzaldi-";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rHistogramViewer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gHistogramViewer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bHistogramViewer))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

			this->isImageShowing = true;
			this->isMenuShowing = !this->isImageShowing;
		}

#pragma endregion

	private:
		Void inverseVisibility()
		{
			this->isImageShowing = !this->isImageShowing;
			this->isMenuShowing = !this->isImageShowing;

			this->pictureBox->Visible = this->isImageShowing;

			this->toNegativeButton->Visible = this->isMenuShowing;
			this->toGraysButton->Visible = this->isMenuShowing;
			this->imgAddButton->Visible = this->isMenuShowing;
			this->imgSubstButton->Visible = this->isMenuShowing;
			this->operNOTButton->Visible = this->isMenuShowing;
			this->operANDButton->Visible = this->isMenuShowing;
			this->operORButton->Visible = this->isMenuShowing;
			this->operXORButton->Visible = this->isMenuShowing;
			this->imgMoveButton->Visible = this->isMenuShowing;
			this->imgCWButton->Visible = this->isMenuShowing;
			this->imgCCWButton->Visible = this->isMenuShowing;
			this->imgVertFlipButton->Visible = this->isMenuShowing;
			this->imgZoomInButton->Visible = this->isMenuShowing;
			this->abrighteningButton->Visible = this->isMenuShowing;
			this->aBrightnessFactor->Visible = this->isMenuShowing;
			this->gBrighteningButton->Visible = this->isMenuShowing;
			this->gBrightnessFactor->Visible = this->isMenuShowing;
			this->logTransformButton->Visible = this->isMenuShowing;
			this->inverseLogButton->Visible = this->isMenuShowing;
			this->powerTransformButton->Visible = this->isMenuShowing;
			this->imgZoomOutButton->Visible = this->isMenuShowing;
			this->imgHorFlipButton->Visible = this->isMenuShowing;
			this->imgPOFFlipButton->Visible = this->isMenuShowing;
			this->imgXYFlipButton->Visible = this->isMenuShowing;
			this->logValue->Visible = this->isMenuShowing;
			this->inverseLogValue->Visible = this->isMenuShowing;
			this->powerValue->Visible = this->isMenuShowing;
			this->xGeserValue->Visible = this->isMenuShowing;
			this->yGeserValue->Visible = this->isMenuShowing;
			this->xLabel->Visible = this->isMenuShowing;
			this->yLabel->Visible = this->isMenuShowing;
			this->preserveSlicingButton->Visible = this->isMenuShowing;
			this->discardSlicingButton->Visible = this->isMenuShowing;
			this->histEqButton->Visible = this->isMenuShowing;
			this->histSpecificButton->Visible = this->isMenuShowing;
			this->contrastStretchingButton->Visible = this->isMenuShowing;
			this->elemen00->Visible = this->isMenuShowing;
			this->elemen01->Visible = this->isMenuShowing;
			this->elemen02->Visible = this->isMenuShowing;
			this->elemen10->Visible = this->isMenuShowing;
			this->elemen11->Visible = this->isMenuShowing;
			this->elemen12->Visible = this->isMenuShowing;
			this->elemen20->Visible = this->isMenuShowing;
			this->elemen21->Visible = this->isMenuShowing;
			this->elemen22->Visible = this->isMenuShowing;
			this->convoluteButton->Visible = this->isMenuShowing;
			this->widthValue->Visible = this->isMenuShowing;
			this->heightValue->Visible = this->isMenuShowing;
			this->widthLabel->Visible = this->isMenuShowing;
			this->heightLabel->Visible = this->isMenuShowing;
			this->meanFilterButton->Visible = this->isMenuShowing;
			this->medianFilterButton->Visible = this->isMenuShowing;
			this->highPassButton->Visible = this->isMenuShowing;
			this->unsharpButton->Visible = this->isMenuShowing;
			this->highBoostButton->Visible = this->isMenuShowing;
			this->gaussianButton->Visible = this->isMenuShowing;
			this->bitSlicingValue->Visible = this->isMenuShowing;
			this->bitPlaneButton->Visible = this->isMenuShowing;

			this->rHistogramViewer->Visible = false;
			this->gHistogramViewer->Visible = false;
			this->bHistogramViewer->Visible = false;
		}

		Void renderImage(Custom::Image* foto)
		{
			int width = foto->getCols();
			int height = foto->getRows();

			if (width + 200 > 1280)
			{
				if (height > 720)
				{
					this->ClientSize = System::Drawing::Size(1280, 720);
				}
				else
				{
					this->ClientSize = System::Drawing::Size(1280, height+12);
				}
			}
			else
			{
				if (height > 720)
				{
					this->ClientSize = System::Drawing::Size(width+200, 720);
				}
				else
				{
					this->ClientSize = System::Drawing::Size(width+200, height + 12);
				}
			}

			this->pictureBox->Size = System::Drawing::Size(width, height);

			System::Drawing::Bitmap^ bmp = (gcnew System::Drawing::Bitmap(width, height));
			for (int i = 0; i < width; i++)
			{
				for (int j = 0; j < height; j++)
				{
					bmp->SetPixel(i, j, Color::FromArgb(foto->getCell(0, j, i), foto->getCell(1, j, i), foto->getCell(2, j, i)));
				}
			}
			this->pictureBox->Image = bmp;
		}

		Void toEditorButton_Click(Object^ sender, EventArgs^ e)
		{
			inverseVisibility();
		}

		Void continousEdit()
		{
			if (this->moveCount > 0)
			{
				*this->renderedImg = translation(*this->dynamicImg, this->m, this->n);
				if (zoomLevel == -1)
				{
					*this->renderedImg = zoomOut(*this->renderedImg);
				}
				else if (zoomLevel == 1)
				{
					*this->renderedImg = zoomIn(*this->renderedImg);
				}
			}
			else
			{
				if (zoomLevel == -1)
				{
					*this->renderedImg = zoomOut(*this->dynamicImg);
				}
				else if (zoomLevel == 0)
				{
					*this->renderedImg = *this->dynamicImg;
				}
				else if (zoomLevel == 1)
				{
					*this->renderedImg = zoomIn(*this->dynamicImg);
				}
			}
			renderImage(this->renderedImg);
		}

		Void openSecondaryImg()
		{
			if (this->formatStatus == 1) this->dialog->Filter = "PPM files (*.ppm)|*.ppm*";
			else if (this->formatStatus == 2) this->dialog->Filter = "PGM files (*.pgm)|*.pgm*";

			this->dialog->ShowDialog();
			char* namaFile = (char*)(void*)Marshal::StringToHGlobalAnsi(this->dialog->FileName->Replace('\\', '/'));
			
			if (this->formatStatus == 1) *this->secondaryImg = readPPM(namaFile);
			else if (this->formatStatus == 2) *this->secondaryImg = readPGM(namaFile);
		}

		Void openPPMButton_Click(Object^ sender, EventArgs^ e)
		{
			this->m = 0;
			this->n = 0;
			this->moveCount = 0;
			this->zoomLevel = 0;
			this->formatStatus = 1;

			this->dialog->FileName = "";
			this->toEditorButton->Visible = true;
			this->saveTempButton->Visible = true;
			this->showHistogramButton->Visible = true;
			this->dialog->Filter = "PPM files (*.ppm)|*.ppm*";
			this->dialog->ShowDialog();
			char* namaFile = (char*)(void*)Marshal::StringToHGlobalAnsi(this->dialog->FileName->Replace('\\', '/'));

			*this->defaultImg = readPPM(namaFile);
			*this->dynamicImg = readPPM(namaFile);

			this->discardButton->Visible = true;
			renderImage(this->defaultImg);

			this->rHistogramViewer->Visible = false;
			this->gHistogramViewer->Visible = false;
			this->bHistogramViewer->Visible = false;
		}

		Void openPGMButton_Click(Object^ sender, EventArgs^ e)
		{
			this->m = 0;
			this->n = 0;
			this->moveCount = 0;
			this->zoomLevel = 0;
			this->formatStatus = 2;

			this->dialog->FileName = "";
			this->toEditorButton->Visible = true;
			this->saveTempButton->Visible = true;
			this->showHistogramButton->Visible = true;
			this->dialog->Filter = "PGM files (*.pgm)|*.pgm*";
			this->dialog->ShowDialog();
			char* namaFile = (char*)(void*)Marshal::StringToHGlobalAnsi(this->dialog->FileName->Replace('\\', '/'));

			*this->defaultImg = readPGM(namaFile);
			*this->dynamicImg = readPGM(namaFile);

			this->discardButton->Visible = true;
			renderImage(this->defaultImg);

			this->rHistogramViewer->Visible = false;
			this->gHistogramViewer->Visible = false;
			this->bHistogramViewer->Visible = false;
		}

		/*Void openPBMButton_Click(Object^ sender, EventArgs^ e)
		{
		}*/

		Void openBMPButton_Click(Object^ sender, EventArgs^ e)
		{
			this->m = 0;
			this->n = 0;
			this->moveCount = 0;
			this->zoomLevel = 0;
			this->formatStatus = 1;

			this->dialog->FileName = "";
			this->toEditorButton->Visible = true;
			this->saveTempButton->Visible = true;
			this->showHistogramButton->Visible = true;
			this->dialog->Filter = "BMP files (*.bmp)|*.bmp*";
			this->dialog->ShowDialog();
			char* namaFile = (char*)(void*)Marshal::StringToHGlobalAnsi(this->dialog->FileName->Replace('\\', '/'));

			*this->defaultImg = readBMP(namaFile);
			*this->dynamicImg = readBMP(namaFile);

			this->discardButton->Visible = true;
			renderImage(this->defaultImg);

			this->rHistogramViewer->Visible = false;
			this->gHistogramViewer->Visible = false;
			this->bHistogramViewer->Visible = false;
		}

		Void saveTempButton_Click(Object^ sender, EventArgs^ e)
		{
			this->saveDialog->FileName = "";
			
			if (this->formatStatus == 1) this->saveDialog->Filter = "PPM files (*.ppm)|*.ppm*";
			else if (this->formatStatus == 2) this->saveDialog->Filter = "PPM files (*.pgm)|*.pgm*";
			
			this->saveDialog->RestoreDirectory = true;
			this->saveDialog->ShowDialog();
			if (this->saveDialog->FileName != "")
			{
				if (this->formatStatus == 1) {
					this->saveDialog->FileName = this->saveDialog->FileName + ".ppm";
					char* namaFile = (char*)(void*)Marshal::StringToHGlobalAnsi(this->saveDialog->FileName);
					writePPM(namaFile, *this->dynamicImg);
				}
				else if (this->formatStatus == 2) {
					this->saveDialog->FileName = this->saveDialog->FileName + ".pgm";
					char* namaFile = (char*)(void*)Marshal::StringToHGlobalAnsi(this->saveDialog->FileName);
					writePGM(namaFile, *this->dynamicImg);
				}
			}
		}

		Void discardButton_Click(Object^ sender, EventArgs^ e)
		{
			this->m = 0;
			this->n = 0;
			this->moveCount = 0;
			this->zoomLevel = 0;

			*this->dynamicImg = *this->defaultImg;
			renderImage(this->defaultImg);

			this->rHistogramViewer->Visible = false;
			this->gHistogramViewer->Visible = false;
			this->bHistogramViewer->Visible = false;
		}

		Void abrighteningButton_Click(Object^ sender, EventArgs^ e)
		{
			double scale;

			if (this->aBrightnessFactor->SelectedIndex == 0) scale = 255;
			else if (this->aBrightnessFactor->SelectedIndex == 1) scale = 100;
			else if (this->aBrightnessFactor->SelectedIndex == 2) scale = 50;
			else if (this->aBrightnessFactor->SelectedIndex == 3) scale = 25;
			else if (this->aBrightnessFactor->SelectedIndex == 4) scale = 10;
			else if (this->aBrightnessFactor->SelectedIndex == 5) scale = 0;
			else if (this->aBrightnessFactor->SelectedIndex == 6) scale = -10;
			else if (this->aBrightnessFactor->SelectedIndex == 7) scale = -25;
			else if (this->aBrightnessFactor->SelectedIndex == 8) scale = -50;
			else if (this->aBrightnessFactor->SelectedIndex == 9) scale = -100;
			else if (this->aBrightnessFactor->SelectedIndex == 10) scale = -255;

			*this->dynamicImg = brightening(*this->dynamicImg, 0, scale);
			continousEdit();
			inverseVisibility();
		}

		Void gBrighteningButton_Click(Object^ sender, EventArgs^ e)
		{
			double scale;
			if (this->gBrightnessFactor->SelectedIndex == 0) scale = 1.5;
			else if (this->gBrightnessFactor->SelectedIndex == 1) scale = 1.25;
			else if (this->gBrightnessFactor->SelectedIndex == 2) scale = 1;
			else if (this->gBrightnessFactor->SelectedIndex == 3) scale = 0.75;
			else if (this->gBrightnessFactor->SelectedIndex == 4) scale = 0.5;
			else if (this->gBrightnessFactor->SelectedIndex == 5) scale = 0.25;
			else if (this->gBrightnessFactor->SelectedIndex == 6) scale = 0;

			*this->dynamicImg = brightening(*this->dynamicImg, 1, scale);
			continousEdit();
			inverseVisibility();
		}

		Void toNegativeButton_Click(Object^ sender, EventArgs^ e)
		{
			*this->dynamicImg = negatif(*this->dynamicImg);
			continousEdit();
			inverseVisibility();
		}

		Void toGraysButton_Click(Object^ sender, EventArgs^ e)
		{
			*this->dynamicImg = convert_to_Grayscale(*this->dynamicImg);
			continousEdit();
			inverseVisibility();
		}

		Void imgMoveButton_Click(Object^ sender, EventArgs^ e)
		{
			this->moveCount = this->moveCount + 1;

			if (this->xGeserValue->SelectedIndex == 0) this->n = this->n + 100;
			else if (this->xGeserValue->SelectedIndex == 1) this->n = this->n + 50;
			else if (this->xGeserValue->SelectedIndex == 2) this->n = this->n + 25;
			else if (this->xGeserValue->SelectedIndex == 3) this->n = this->n + 10;
			else if (this->xGeserValue->SelectedIndex == 4) this->n = this->n + 0;
			else if (this->xGeserValue->SelectedIndex == 5) this->n = this->n - 10;
			else if (this->xGeserValue->SelectedIndex == 6) this->n = this->n - 25;
			else if (this->xGeserValue->SelectedIndex == 7) this->n = this->n - 50;
			else if (this->xGeserValue->SelectedIndex == 8) this->n = this->n - 100;

			if (this->yGeserValue->SelectedIndex == 0) this->m = this->m - 100;
			else if (this->yGeserValue->SelectedIndex == 1) this->m = this->m - 50;
			else if (this->yGeserValue->SelectedIndex == 2) this->m = this->m - 25;
			else if (this->yGeserValue->SelectedIndex == 3) this->m = this->m - 10;
			else if (this->yGeserValue->SelectedIndex == 4) this->m = this->m - 0;
			else if (this->yGeserValue->SelectedIndex == 5) this->m = this->m + 10;
			else if (this->yGeserValue->SelectedIndex == 6) this->m = this->m + 25;
			else if (this->yGeserValue->SelectedIndex == 7) this->m = this->m + 50;
			else if (this->yGeserValue->SelectedIndex == 8) this->m = this->m + 100;

			*this->renderedImg = translation(*this->dynamicImg, this->m, this->n);
			renderImage(this->renderedImg);
			inverseVisibility();
		}

		Void imgCWButton_Click(Object^ sender, EventArgs^ e)
		{
			*this->dynamicImg = rotate90CW(*this->dynamicImg);
			continousEdit();
			inverseVisibility();
		}

		Void imgCCWButton_Click(Object^ sender, EventArgs^ e)
		{
			*this->dynamicImg = rotate90CCW(*this->dynamicImg);
			continousEdit();
			inverseVisibility();
		}

		Void imgZoomInButton_Click(Object^ sender, EventArgs^ e)
		{
			if (this->zoomLevel < 1) this->zoomLevel = this->zoomLevel + 1;
			continousEdit();
			inverseVisibility();
		}

		Void imgZoomOutButton_Click(Object^ sender, EventArgs^ e)
		{
			if (this->zoomLevel > -1) this->zoomLevel = this->zoomLevel - 1;
			continousEdit();
			inverseVisibility();
		}

		Void imgAddButton_Click(Object^ sender, EventArgs^ e)
		{
			openSecondaryImg();
			*this->combinedImg = addition(*this->dynamicImg, *this->secondaryImg);
			renderImage(this->combinedImg);
			inverseVisibility();
		}

		Void imgSubstButton_Click(Object^ sender, EventArgs^ e)
		{
			openSecondaryImg();
			*this->dynamicImg = substraction(*this->dynamicImg, *this->secondaryImg);
			continousEdit();
			inverseVisibility();
		}

		Void operNOTButton_Click(Object^ sender, EventArgs^ e)
		{
			*this->dynamicImg = NOTOperation(*this->dynamicImg);
			continousEdit();
			inverseVisibility();
		}

		Void operANDButton_Click(Object^ sender, EventArgs^ e)
		{
			openSecondaryImg();
			*this->combinedImg = ANDOperation(*this->dynamicImg, *this->secondaryImg);
			renderImage(this->combinedImg);
			inverseVisibility();
		}

		Void operORButton_Click(Object^ sender, EventArgs^ e)
		{
			openSecondaryImg();
			*this->dynamicImg = OROperation(*this->dynamicImg, *this->secondaryImg);
			continousEdit();
			inverseVisibility();
		}

		Void operXORButton_Click(Object^ sender, EventArgs^ e)
		{
			openSecondaryImg();
			*this->dynamicImg = XOROperation(*this->dynamicImg, *this->secondaryImg);
			continousEdit();
			inverseVisibility();
		}

		Void imgVertFlipButton_Click(Object^ sender, EventArgs^ e)
		{
			*this->dynamicImg = verticalFlip(*this->dynamicImg);
			continousEdit();
			inverseVisibility();
		}

		Void imgHorFlipButton_Click(Object^ sender, EventArgs^ e)
		{
			*this->dynamicImg = horizontalFlip(*this->dynamicImg);
			continousEdit();
			inverseVisibility();
		}

		Void imgPOFFlipButton_Click(Object^ sender, EventArgs^ e)
		{
			*this->dynamicImg = POFFlip(*this->dynamicImg);
			continousEdit();
			inverseVisibility();
		}

		Void imgXYFlipButton_Click(Object^ sender, EventArgs^ e)
		{
			*this->dynamicImg = xyFlip(*this->dynamicImg);
			continousEdit();
			inverseVisibility();
		}
		
		Void logTransformButton_Click(Object^ sender, EventArgs^ e)
		{
			double c;

			if (this->logValue->SelectedIndex == 0) c = 120;
			else if (this->logValue->SelectedIndex == 1) c = 100;
			else if (this->logValue->SelectedIndex == 2) c = 80;
			else if (this->logValue->SelectedIndex == 3) c = 60;
			else if (this->logValue->SelectedIndex == 4) c = 40;
			else if (this->logValue->SelectedIndex == 5) c = 20;

			*this->dynamicImg = transformation_log(*this->dynamicImg, c);
			continousEdit();
			inverseVisibility();
		}

		Void inverseLogButton_Click(Object^ sender, EventArgs^ e)
		{
			double c;

			if (this->inverseLogValue->SelectedIndex == 0) c = 150;
			else if (this->inverseLogValue->SelectedIndex == 1) c = 125;
			else if (this->inverseLogValue->SelectedIndex == 2) c = 100;
			else if (this->inverseLogValue->SelectedIndex == 3) c = 75;
			else if (this->inverseLogValue->SelectedIndex == 4) c = 50;
			else if (this->inverseLogValue->SelectedIndex == 5) c = 25;

			*this->dynamicImg = transformation_log_inverse(*this->dynamicImg, c);
			continousEdit();
			inverseVisibility();
		}
		
		Void powerTransformButton_Click(Object^ sender, EventArgs^ e)
		{
			double pangkat;

			if (this->powerValue->SelectedIndex == 0) pangkat = 1.1;
			else if (this->powerValue->SelectedIndex == 1) pangkat = 1.05;
			else if (this->powerValue->SelectedIndex == 2) pangkat = 1.01;
			else if (this->powerValue->SelectedIndex == 3) pangkat = 1;
			else if (this->powerValue->SelectedIndex == 4) pangkat = 0.99;
			else if (this->powerValue->SelectedIndex == 5) pangkat = 0.95;
			else if (this->powerValue->SelectedIndex == 6) pangkat = 0.9;

			*this->dynamicImg = transformation_pangkat(*this->dynamicImg, 1, pangkat);
			continousEdit();
			inverseVisibility();
		}

		Void preserveSlicingButton_Click(Object^ sender, EventArgs^ e)
		{
			unsigned char temp;
			temp = (unsigned char) this->dynamicImg->getGray();
			*this->dynamicImg = preserveBackgroundGrayLevelSlicing(*this->dynamicImg, 0.25*(temp+1)-1, 0.75*(temp+1), temp);
			continousEdit();
			inverseVisibility();
		}
		
		Void discardSlicingButton_Click(Object^ sender, EventArgs^ e)
		{
			unsigned char temp;
			temp = (unsigned char) this->dynamicImg->getGray();
			*this->dynamicImg = discardBackgroundGrayLevelSlicing(*this->dynamicImg, 0.25*(temp+1)-1, 0.75*(temp+1), 0.25*(temp+1)-1, 0.75*(temp+1));
			continousEdit();
			inverseVisibility();
		}

		Void contrastStretchingButton_Click(Object^ sender, EventArgs^ e)
		{
			unsigned char temp;
			temp = (unsigned char) this->dynamicImg->getGray();
			*this->dynamicImg = contrastStretching(*this->dynamicImg, 0.25 * (temp + 1) - 1, 0.75 * (temp + 1));
			continousEdit();
			inverseVisibility();
		}

		Void bitPlaneButton_Click(Object^ sender, EventArgs^ e)
		{
			*this->dynamicImg = bitPlaneSlicing(*this->dynamicImg, this->bitSlicingValue->SelectedIndex);
			continousEdit();
			inverseVisibility();
		}

		Void histEqButton_Click(Object^ sender, EventArgs^ e)
		{
			*this->dynamicImg = histogramEqualization(*this->dynamicImg);
			continousEdit();
			inverseVisibility();
		}

		Void showHistogramButton_Click(Object^ sender, EventArgs^ e)
		{
			float* rHistoArray;
			float* gHistoArray;
			float* bHistoArray;

			System::Drawing::Bitmap^ rHistoRender = (gcnew System::Drawing::Bitmap(256, 100));
			System::Drawing::Bitmap^ gHistoRender = (gcnew System::Drawing::Bitmap(256, 100));
			System::Drawing::Bitmap^ bHistoRender = (gcnew System::Drawing::Bitmap(256, 100));

			rHistoArray = histogram(*this->dynamicImg, 0);
			for (int i = 0; i < 256; i++)
			{
				for (int j = 0; j < 100; j++)
				{
					if (j < (100-(5000*rHistoArray[i]))) rHistoRender->SetPixel(i, j, Color::FromArgb(240, 240, 240));
					else rHistoRender->SetPixel(i, j, Color::FromArgb(160, 0, 0));
				}
			}
			this->rHistogramViewer->Image = rHistoRender;
			this->rHistogramViewer->Visible = !this->rHistogramViewer->Visible;

			gHistoArray = histogram(*this->dynamicImg, 1);
			for (int i = 0; i < 256; i++)
			{
				for (int j = 0; j < 100; j++)
				{
					if (j < (100 - (5000 * gHistoArray[i]))) gHistoRender->SetPixel(i, j, Color::FromArgb(240, 240, 240));
					else gHistoRender->SetPixel(i, j, Color::FromArgb(0, 160, 0));
				}
			}
			this->gHistogramViewer->Image = gHistoRender;
			this->gHistogramViewer->Visible = !this->gHistogramViewer->Visible;

			bHistoArray = histogram(*this->dynamicImg, 2);
			for (int i = 0; i < 256; i++)
			{
				for (int j = 0; j < 100; j++)
				{
					if (j < (100 - (5000 * bHistoArray[i]))) bHistoRender->SetPixel(i, j, Color::FromArgb(240, 240, 240));
					else bHistoRender->SetPixel(i, j, Color::FromArgb(0, 0, 160));
				}
			}
			this->bHistogramViewer->Image = bHistoRender;
			this->bHistogramViewer->Visible = !this->bHistogramViewer->Visible;
		}

		/*Void gaussianButton_Click(Object^ sender, EventArgs^ e)
		{
			*this->dynamicImg = penapis_gaussian(*this->dynamicImg);
			continousEdit();
			inverseVisibility();
		}

		Void highPassButton_Click(Object^ sender, EventArgs^ e)
		{
			*this->dynamicImg = highpass(*this->dynamicImg);
			continousEdit();
			inverseVisibility();
		}

		Void unsharpButton(Object^ sender, EventArgs^ e)
		{
			*this->dynamicImg = unsharpMasking(*this->dynamicImg);
			continousEdit();
			inverseVisibility();
		}*/
	};
};