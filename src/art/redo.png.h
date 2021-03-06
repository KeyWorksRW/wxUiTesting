#ifndef REDO_PNG_H
#define REDO_PNG_H

#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>

static const unsigned char redo_png[] =
{
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 
	0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x18, 
	0x00, 0x00, 0x00, 0x18, 0x08, 0x06, 0x00, 0x00, 0x00, 0xE0, 
	0x77, 0x3D, 0xF8, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 
	0x73, 0x00, 0x00, 0x0B, 0x13, 0x00, 0x00, 0x0B, 0x13, 0x01, 
	0x00, 0x9A, 0x9C, 0x18, 0x00, 0x00, 0x03, 0x63, 0x49, 0x44, 
	0x41, 0x54, 0x48, 0xC7, 0xED, 0x95, 0x4D, 0x68, 0x1D, 0x55, 
	0x14, 0xC7, 0x7F, 0xE7, 0xDC, 0x3B, 0xF3, 0xDE, 0xE4, 0x83, 
	0xB4, 0x85, 0x08, 0x2D, 0x55, 0x6C, 0x4D, 0x41, 0xA8, 0x90, 
	0x26, 0xBB, 0x22, 0xB4, 0x0A, 0x85, 0x6E, 0xFC, 0x40, 0xA1, 
	0x20, 0x04, 0x04, 0x17, 0x4A, 0x45, 0x10, 0xA9, 0x8B, 0x6C, 
	0x44, 0x8A, 0x52, 0xEA, 0x42, 0x41, 0x2C, 0x48, 0x45, 0x2C, 
	0x6E, 0x2A, 0x88, 0xEE, 0xC4, 0x65, 0x11, 0x41, 0xD1, 0x45, 
	0xB1, 0x50, 0x84, 0xD0, 0xD6, 0x24, 0xB5, 0x31, 0x91, 0xA6, 
	0xAD, 0x89, 0x35, 0xEF, 0xBD, 0xCC, 0x9B, 0xB9, 0xF7, 0xB8, 
	0x98, 0xD7, 0xD7, 0xA4, 0x4D, 0xAC, 0xD6, 0x95, 0xE0, 0x85, 
	0xCB, 0x0C, 0xC3, 0x99, 0xFF, 0xEF, 0x9E, 0xCF, 0x0B, 0xFF, 
	0xF5, 0x25, 0x77, 0x32, 0xF8, 0xE4, 0xD4, 0x65, 0x93, 0x56, 
	0x84, 0x68, 0x20, 0xD5, 0x0F, 0x22, 0x82, 0x38, 0x41, 0x7A, 
	0x1C, 0x07, 0xF6, 0x0E, 0xCA, 0x5D, 0x01, 0xDE, 0xFD, 0xFC, 
	0x92, 0xF9, 0xA6, 0x75, 0x04, 0x3B, 0xA2, 0xC2, 0x8A, 0x2D, 
	0xDD, 0x67, 0xEC, 0x81, 0xE7, 0x1F, 0xDB, 0x2A, 0x7F, 0x1B, 
	0xF0, 0xE6, 0x89, 0x8B, 0x16, 0x97, 0x4A, 0x54, 0x6F, 0x15, 
	0x5E, 0xF1, 0x7E, 0x03, 0x4C, 0xF5, 0xCD, 0xF5, 0x79, 0x5E, 
	0x79, 0xE6, 0x5E, 0xB9, 0x23, 0xE0, 0xD0, 0xFB, 0x93, 0x66, 
	0x0B, 0xED, 0x4A, 0xAC, 0x03, 0x50, 0x01, 0x51, 0xE9, 0x0A, 
	0x9B, 0x05, 0x9C, 0xFA, 0x9B, 0x21, 0xEB, 0x6C, 0xDD, 0xE0, 
	0x39, 0xFC, 0xDC, 0x36, 0x59, 0x17, 0x30, 0xF6, 0xF6, 0x19, 
	0x4B, 0xAF, 0x26, 0x88, 0x82, 0x3A, 0xE9, 0x42, 0xF4, 0x16, 
	0x2F, 0x36, 0x6F, 0x6A, 0x91, 0x26, 0x8E, 0x99, 0xF9, 0x14, 
	0xCC, 0xBA, 0x00, 0x0C, 0x9A, 0x03, 0x6D, 0x3E, 0x7C, 0x79, 
	0xB8, 0xAB, 0xEB, 0x57, 0x02, 0x66, 0x2E, 0x40, 0xBE, 0xD8, 
	0xC0, 0x54, 0x70, 0x4E, 0xF0, 0x89, 0x92, 0x24, 0x42, 0x2D, 
	0x55, 0xEA, 0x35, 0x47, 0x56, 0x53, 0xBC, 0x13, 0xB6, 0xF8, 
	0x84, 0x97, 0xC6, 0x86, 0x78, 0xE7, 0xE3, 0x73, 0x4C, 0xCD, 
	0x79, 0x30, 0x10, 0x33, 0x30, 0x48, 0x5C, 0x7D, 0xED, 0x10, 
	0x0D, 0x1F, 0x9D, 0xB6, 0x4B, 0x5F, 0xFC, 0x5C, 0x55, 0x87, 
	0x13, 0xC4, 0x69, 0x15, 0x22, 0x15, 0xE8, 0x84, 0x07, 0x84, 
	0xD4, 0x0B, 0xFB, 0x46, 0x3D, 0x1F, 0xBD, 0x3E, 0x4A, 0xB3, 
	0x95, 0xF3, 0xC6, 0xF1, 0x09, 0x7E, 0x9A, 0xF5, 0xA8, 0x00, 
	0x11, 0x88, 0xC6, 0xB5, 0xBE, 0xC8, 0x57, 0x47, 0x46, 0x64, 
	0x95, 0x07, 0xCD, 0xB9, 0x06, 0x9A, 0x3A, 0xD4, 0x0B, 0xE2, 
	0x15, 0x71, 0x42, 0xE2, 0x23, 0x07, 0xF6, 0x66, 0x3C, 0xB5, 
	0x67, 0x90, 0x6D, 0x5B, 0xEA, 0x38, 0xAD, 0x6C, 0xD3, 0x24, 
	0xC1, 0xCC, 0xC8, 0xEA, 0x29, 0xAF, 0xBD, 0xF0, 0x20, 0x4F, 
	0xBE, 0xFA, 0x03, 0x53, 0x73, 0x4A, 0x4F, 0xAA, 0xF4, 0xA6, 
	0x4A, 0x7F, 0x5F, 0xC2, 0x9A, 0x21, 0x72, 0x75, 0x45, 0xBD, 
	0x22, 0x5E, 0xF1, 0xDE, 0x78, 0xEF, 0xC5, 0x41, 0xF6, 0xEF, 
	0xDE, 0x4A, 0x88, 0x91, 0xC5, 0xEB, 0x4D, 0x42, 0xA8, 0xEC, 
	0x4A, 0x0D, 0xE4, 0x79, 0x0E, 0x40, 0x51, 0x16, 0x68, 0xAA, 
	0x2C, 0x9B, 0xD0, 0x6A, 0x04, 0xAE, 0x2C, 0x16, 0x0C, 0x6C, 
	0xCC, 0xD6, 0x01, 0xD4, 0x1C, 0x9A, 0x28, 0x9A, 0x28, 0x8F, 
	0xEE, 0x8C, 0x3C, 0x32, 0x7A, 0x0F, 0xA7, 0x27, 0x2E, 0x33, 
	0x7E, 0x72, 0x9E, 0xF9, 0x46, 0xDA, 0xB5, 0xDB, 0x7D, 0x7F, 
	0xE0, 0xD8, 0xC1, 0x21, 0x5A, 0x79, 0x9B, 0x43, 0x1F, 0x5C, 
	0xE4, 0xFC, 0xD5, 0x14, 0x5F, 0x8F, 0xC4, 0x42, 0xAA, 0x6A, 
	0xF3, 0xB2, 0x9E, 0x07, 0x1E, 0x4D, 0x2B, 0xC0, 0xE8, 0x0E, 
	0x25, 0x6F, 0xE7, 0x1C, 0x3F, 0xF5, 0x1B, 0xD7, 0xE8, 0xC7, 
	0xF7, 0xDD, 0xA8, 0x51, 0x20, 0x5D, 0x66, 0xF1, 0xFA, 0x12, 
	0xE3, 0x27, 0x7F, 0xE5, 0xF4, 0x6C, 0x1D, 0x97, 0x45, 0xC4, 
	0x47, 0xC4, 0x05, 0x50, 0xC1, 0xA5, 0xEB, 0x02, 0x1C, 0xAE, 
	0xA6, 0x55, 0x2E, 0x5C, 0xA0, 0x28, 0x0A, 0x72, 0x51, 0x92, 
	0xDE, 0xA4, 0x4A, 0xB6, 0x80, 0x99, 0xD1, 0x0A, 0x25, 0xE3, 
	0x9F, 0xCD, 0x73, 0x76, 0xB1, 0x1F, 0xDF, 0x1B, 0x89, 0xED, 
	0x48, 0x68, 0x07, 0x44, 0xAB, 0xEE, 0xAB, 0x25, 0xAD, 0xB5, 
	0x01, 0x3E, 0x73, 0x68, 0xEA, 0x70, 0x75, 0xC7, 0xD4, 0x42, 
	0x9B, 0xA2, 0x5D, 0xB0, 0x77, 0xC8, 0x98, 0x3C, 0xEF, 0x91, 
	0x4E, 0x86, 0xCD, 0x8C, 0xC9, 0xB0, 0x89, 0x58, 0x48, 0x57, 
	0x3C, 0xFA, 0x80, 0x38, 0x21, 0x88, 0x80, 0x04, 0xCE, 0xBE, 
	0x35, 0x72, 0x7B, 0x1F, 0x5C, 0x38, 0xF6, 0x90, 0x0C, 0x1F, 
	0x9D, 0xB6, 0xF6, 0xEF, 0x6D, 0x5C, 0xE6, 0xF8, 0xEE, 0x4A, 
	0xC6, 0xD3, 0x57, 0x97, 0xD8, 0xBF, 0xB3, 0x9F, 0xC1, 0xBE, 
	0x05, 0x66, 0x1B, 0xEE, 0xE6, 0x49, 0xCC, 0x30, 0x83, 0x6F, 
	0x7F, 0x11, 0xA6, 0x96, 0xFA, 0x09, 0x5A, 0x09, 0x03, 0xF4, 
	0x6C, 0xC9, 0x56, 0xF5, 0xC1, 0x2A, 0x0F, 0x06, 0xB6, 0xA7, 
	0x2C, 0x9C, 0x8B, 0xB8, 0x9A, 0xA3, 0xAC, 0xD7, 0x38, 0x72, 
	0xA6, 0xC9, 0xD8, 0xF6, 0x3F, 0xD8, 0xB5, 0xB9, 0xCE, 0x2E, 
	0xEF, 0x6E, 0x9B, 0x59, 0x33, 0xCD, 0x9C, 0x19, 0xAB, 0xC2, 
	0x27, 0xAE, 0x3A, 0xF4, 0x8F, 0x87, 0x77, 0xC8, 0x5F, 0xCE, 
	0xA2, 0x87, 0x4F, 0x4C, 0xDB, 0x72, 0xC3, 0xE3, 0x33, 0xDF, 
	0xC9, 0x89, 0x23, 0x8D, 0x0D, 0x7A, 0x5C, 0xA8, 0x66, 0x85, 
	0x19, 0xB1, 0x34, 0x62, 0x19, 0x69, 0x14, 0x09, 0xCB, 0x45, 
	0x42, 0x68, 0x05, 0xCA, 0x66, 0x49, 0xB6, 0x31, 0xF2, 0xFD, 
	0xC1, 0x07, 0xE4, 0x8E, 0xD3, 0x74, 0xCF, 0xA7, 0xB3, 0x16, 
	0x42, 0x8A, 0xCB, 0x3C, 0x2E, 0x73, 0xB8, 0x4E, 0x03, 0xA2, 
	0x82, 0x45, 0xC3, 0x8A, 0x48, 0xC8, 0x23, 0x21, 0x0F, 0x94, 
	0x8D, 0x82, 0xB2, 0x59, 0x92, 0xD6, 0x4B, 0xBE, 0x79, 0xF6, 
	0x3E, 0xF9, 0x47, 0x17, 0xCE, 0xBE, 0x53, 0x4B, 0xA6, 0xB5, 
	0x2A, 0xE9, 0x9A, 0x28, 0xD2, 0x01, 0xC4, 0x3C, 0x52, 0x2E, 
	0x97, 0x94, 0xCD, 0x92, 0xD8, 0x8E, 0x7C, 0xFD, 0xC4, 0x06, 
	0xB9, 0xEB, 0x1B, 0x0D, 0xE0, 0xF1, 0x89, 0x68, 0x22, 0xB2, 
	0x22, 0xC7, 0x46, 0x5C, 0x0E, 0x7C, 0x39, 0x92, 0x08, 0xFF, 
	0xAF, 0x7F, 0xBB, 0xFE, 0x04, 0x24, 0xD7, 0x47, 0xF4, 0x17, 
	0x1A, 0xD4, 0xE7, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 
	0x44, 0xAE, 0x42, 0x60, 0x82, 
};

wxBitmap& redo_png_to_wx_bitmap()
{
	static wxMemoryInputStream memIStream( redo_png, sizeof( redo_png ) );
	static wxImage image( memIStream, wxBITMAP_TYPE_PNG );
	static wxBitmap bmp( image );
	return bmp;
}


#endif //REDO_PNG_H
