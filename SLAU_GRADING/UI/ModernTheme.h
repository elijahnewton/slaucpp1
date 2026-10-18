#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Drawing::Drawing2D;

namespace SLAUGRADING::UI {

    public ref class ModernTheme {
    public:
        static Color Background = Color::FromArgb(30, 30, 46);
        static Color Card = Color::FromArgb(255, 255, 255);
        static Color Accent = Color::FromArgb(0, 191, 166);
        static Color AccentDark = Color::FromArgb(0, 150, 130);
        static Color TextDark = Color::FromArgb(45, 45, 58);
        static Color TextLight = Color::FromArgb(255, 255, 255);
        static Color Muted = Color::FromArgb(140, 140, 160);
        static Color Danger = Color::FromArgb(231, 76, 60);
        static Color Success = Color::FromArgb(46, 204, 113);
        static Color Border = Color::FromArgb(220, 220, 230);

        static Font^ TitleFont = gcnew Font("Segoe UI", 18, FontStyle::Bold);
        static Font^ HeaderFont = gcnew Font("Segoe UI", 12, FontStyle::Bold);
        static Font^ BodyFont = gcnew Font("Segoe UI", 10, FontStyle::Regular);
        static Font^ SmallFont = gcnew Font("Segoe UI", 9, FontStyle::Regular);
        static Font^ MonoFont = gcnew Font("Consolas", 10, FontStyle::Regular);

        static void ApplyBackground(Control^ c) {
            c->BackColor = Background;
        }

        static Panel^ CreateCard(int x, int y, int w, int h) {
            Panel^ p = gcnew Panel();
            p->Location = Point(x, y);
            p->Size = Size(w, h);
            p->BackColor = Card;
            p->Padding = Padding(16);
            return p;
        }

        static Button^ CreateButton(String^ text, int x, int y, int w, int h, Color bg) {
            Button^ b = gcnew Button();
            b->Text = text;
            b->Location = Point(x, y);
            b->Size = Size(w, h);
            b->BackColor = bg;
            b->ForeColor = TextLight;
            b->FlatStyle = FlatStyle::Flat;
            b->FlatAppearance->BorderSize = 0;
            b->Font = gcnew Font("Segoe UI", 10, FontStyle::Bold);
            b->Cursor = Cursors::Hand;
            return b;
        }

        static TextBox^ CreateTextBox(int x, int y, int w, int h) {
            TextBox^ t = gcnew TextBox();
            t->Location = Point(x, y);
            t->Size = Size(w, h);
            t->BorderStyle = BorderStyle::None;
            t->BackColor = Color::FromArgb(245, 245, 250);
            t->ForeColor = TextDark;
            t->Font = BodyFont;
            t->Padding = Padding(6, 3, 6, 3);
            return t;
        }

        static Label^ CreateLabel(String^ text, int x, int y, int w, int h) {
            Label^ l = gcnew Label();
            l->Text = text;
            l->Location = Point(x, y);
            l->Size = Size(w, h);
            l->ForeColor = TextDark;
            l->Font = BodyFont;
            return l;
        }

        static void StyleGrid(DataGridView^ g) {
            g->BackgroundColor = Card;
            g->BorderStyle = BorderStyle::None;
            g->EnableHeadersVisualStyles = false;
            g->GridColor = Border;
            g->RowTemplate->Height = 32;
            g->DefaultCellStyle->BackColor = Card;
            g->DefaultCellStyle->ForeColor = TextDark;
            g->DefaultCellStyle->Font = BodyFont;
            g->DefaultCellStyle->SelectionBackColor = Color::FromArgb(230, 255, 250);
            g->DefaultCellStyle->SelectionForeColor = TextDark;
            g->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(245, 245, 250);
            g->ColumnHeadersDefaultCellStyle->ForeColor = TextDark;
            g->ColumnHeadersDefaultCellStyle->Font = HeaderFont;
            g->ColumnHeadersHeight = 36;
            g->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            g->AllowUserToResizeRows = false;
        }

        static void DrawRoundedBorder(Object^ sender, PaintEventArgs^ e) {
            Control^ c = (Control^)sender;
            Graphics^ g = e->Graphics;
            g->SmoothingMode = SmoothingMode::AntiAlias;
            int r = 12;
            GraphicsPath^ path = gcnew GraphicsPath();
            Rectangle rect = Rectangle(0, 0, c->Width - 1, c->Height - 1);
            int d = r * 2;
            path->AddArc(rect.X, rect.Y, d, d, 180, 90);
            path->AddArc(rect.Right - d, rect.Y, d, d, 270, 90);
            path->AddArc(rect.Right - d, rect.Bottom - d, d, d, 0, 90);
            path->AddArc(rect.X, rect.Bottom - d, d, d, 90, 90);
            path->CloseAllFigures();
            c->Region = gcnew System::Drawing::Region(path);
            Pen^ pen = gcnew Pen(Border, 1);
            g->DrawPath(pen, path);
            delete pen;
            delete path;
        }
    };

}