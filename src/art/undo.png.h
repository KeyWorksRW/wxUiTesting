#ifndef UNDO_PNG_H
#define UNDO_PNG_H

#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>

static const unsigned char undo_png[] =
{
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 
	0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x18, 
	0x00, 0x00, 0x00, 0x18, 0x08, 0x06, 0x00, 0x00, 0x00, 0xE0, 
	0x77, 0x3D, 0xF8, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 
	0x73, 0x00, 0x00, 0x0B, 0x13, 0x00, 0x00, 0x0B, 0x13, 0x01, 
	0x00, 0x9A, 0x9C, 0x18, 0x00, 0x00, 0x03, 0x74, 0x49, 0x44, 
	0x41, 0x54, 0x48, 0xC7, 0xED, 0x95, 0x4F, 0x68, 0x5D, 0x45, 
	0x14, 0xC6, 0x7F, 0x67, 0x66, 0xDE, 0x7D, 0xF7, 0xBE, 0xF7, 
	0x82, 0xB6, 0x4A, 0x84, 0x44, 0x6B, 0x13, 0x53, 0x34, 0xDD, 
	0xD4, 0x86, 0x2E, 0x04, 0xC5, 0x5A, 0xBA, 0xD4, 0xA5, 0x20, 
	0xD8, 0x85, 0x50, 0x50, 0xC1, 0xA2, 0x14, 0x29, 0x54, 0x51, 
	0xA1, 0x3B, 0x15, 0xA1, 0x94, 0x6E, 0x2C, 0x88, 0x0A, 0x62, 
	0x41, 0xC8, 0x42, 0x50, 0x97, 0x4A, 0x69, 0x41, 0x8A, 0x6E, 
	0x4A, 0x8A, 0x42, 0x95, 0xB6, 0xE9, 0x9F, 0x18, 0x69, 0x53, 
	0x93, 0xB4, 0x49, 0xF3, 0xDE, 0xBD, 0x77, 0x66, 0x8E, 0x8B, 
	0x9B, 0xA4, 0x09, 0x49, 0x8D, 0xD6, 0x95, 0xE0, 0x81, 0x61, 
	0xCE, 0x65, 0xE6, 0x7C, 0xDF, 0xFD, 0xCE, 0x9C, 0x39, 0x03, 
	0xFF, 0x75, 0x93, 0xB5, 0x36, 0x0C, 0x1F, 0x9F, 0x50, 0x9D, 
	0x0B, 0x68, 0x50, 0x54, 0x15, 0x05, 0x50, 0xC0, 0x08, 0x9A, 
	0x19, 0x9E, 0xDF, 0x79, 0x9F, 0xDC, 0x11, 0xC1, 0x47, 0xDF, 
	0x8C, 0xA9, 0x99, 0xA3, 0x02, 0xD5, 0xA5, 0x33, 0xCB, 0xBF, 
	0x01, 0xDF, 0x10, 0xF6, 0x3E, 0xBB, 0x41, 0xFE, 0x36, 0xC1, 
	0xA1, 0x2F, 0x2E, 0x6B, 0x98, 0xF5, 0xF3, 0x00, 0xB7, 0x80, 
	0x56, 0x80, 0xCF, 0xFB, 0x31, 0x82, 0x69, 0x39, 0xDE, 0xD9, 
	0xBD, 0x51, 0xD6, 0x24, 0x38, 0xF0, 0xE9, 0xA8, 0xC6, 0x69, 
	0x5F, 0x01, 0xCE, 0x0F, 0x14, 0x42, 0xF4, 0x88, 0xD8, 0x5B, 
	0x44, 0x51, 0x89, 0x0B, 0x64, 0xB1, 0x9A, 0x65, 0x5D, 0xC2, 
	0xC1, 0x57, 0x1E, 0x92, 0xDB, 0x12, 0xBC, 0x78, 0x78, 0x44, 
	0x1B, 0xD7, 0x13, 0x90, 0x25, 0xE0, 0x22, 0x3C, 0xD0, 0x5D, 
	0x50, 0x94, 0x81, 0xDF, 0x27, 0xB3, 0x65, 0x7F, 0x1F, 0x97, 
	0x80, 0xC7, 0x50, 0xF9, 0xC5, 0xBD, 0x25, 0x47, 0xF7, 0x6D, 
	0x5D, 0xC4, 0x75, 0xCB, 0xD8, 0x66, 0x53, 0x6E, 0xCC, 0x95, 
	0x15, 0x81, 0x08, 0x08, 0xF4, 0xF7, 0x78, 0xF6, 0xEC, 0x7A, 
	0x98, 0x43, 0x9F, 0x9F, 0x65, 0x26, 0x8F, 0xF8, 0xA0, 0xB4, 
	0xF3, 0x48, 0x27, 0x0F, 0xE4, 0x45, 0xA4, 0x2C, 0x15, 0x5F, 
	0x46, 0x42, 0x50, 0x24, 0x2A, 0xF5, 0xA9, 0x64, 0x59, 0x46, 
	0x16, 0x09, 0x76, 0xBC, 0x75, 0x4A, 0x27, 0xAF, 0x74, 0xC0, 
	0x08, 0x18, 0x88, 0x0A, 0x03, 0xBD, 0x9E, 0xD7, 0x5F, 0x18, 
	0x24, 0x4B, 0x13, 0xCE, 0x8E, 0x77, 0x38, 0x36, 0xE2, 0x29, 
	0x7C, 0xA5, 0x4D, 0x15, 0x88, 0x8A, 0xC6, 0x79, 0x15, 0x21, 
	0x56, 0x95, 0x76, 0xB9, 0xCD, 0x96, 0x77, 0x47, 0x75, 0xE4, 
	0xCD, 0x3E, 0x59, 0xA1, 0xE0, 0xC2, 0x95, 0x9C, 0x9B, 0x45, 
	0x64, 0xAE, 0x88, 0xF4, 0xF7, 0x44, 0xDE, 0x7E, 0x69, 0x88, 
	0x2C, 0x4D, 0x50, 0x55, 0x3E, 0x78, 0x75, 0x80, 0xA2, 0x2C, 
	0x01, 0x08, 0x11, 0x46, 0xC7, 0x3B, 0x7C, 0x79, 0x62, 0x82, 
	0xE1, 0xE3, 0x6D, 0x4A, 0x6F, 0xD0, 0x60, 0x50, 0x1F, 0x89, 
	0x5E, 0x99, 0x1B, 0xBF, 0xB9, 0x52, 0xC1, 0xA5, 0x49, 0xC7, 
	0xF5, 0xAB, 0xB3, 0x98, 0x9A, 0x41, 0x9C, 0xC1, 0x24, 0x86, 
	0xD2, 0x97, 0xE4, 0x79, 0xB5, 0xEE, 0x43, 0x20, 0x04, 0x5D, 
	0x3C, 0xB9, 0xAD, 0x8F, 0xAC, 0x63, 0xDB, 0xE6, 0x7B, 0x78, 
	0x72, 0xCB, 0x18, 0xAF, 0x7D, 0x38, 0x89, 0xF7, 0x06, 0xF5, 
	0x82, 0xF8, 0xB8, 0x7A, 0x8A, 0xC4, 0x09, 0xB6, 0x6E, 0x31, 
	0x35, 0x83, 0xA9, 0x19, 0x7E, 0xBD, 0x66, 0xD8, 0x73, 0xF8, 
	0x17, 0x0E, 0xBE, 0xBC, 0x91, 0xAC, 0x9E, 0xB0, 0xEF, 0xE3, 
	0x51, 0x4E, 0x5E, 0xB0, 0x8B, 0x81, 0xDD, 0xCD, 0x82, 0xF7, 
	0x77, 0x75, 0xF3, 0xD4, 0x50, 0x37, 0x3B, 0x1E, 0x9D, 0xE6, 
	0xD8, 0xCF, 0x86, 0x58, 0x0A, 0x52, 0x2E, 0x2F, 0x4C, 0xB3, 
	0xE0, 0xD8, 0x44, 0x30, 0x75, 0x8B, 0x4D, 0x2D, 0x36, 0x73, 
	0xD8, 0xCC, 0xF1, 0xE3, 0x6F, 0x29, 0x7B, 0x3F, 0xB9, 0xC8, 
	0xF4, 0x8D, 0x59, 0x48, 0x2C, 0xAE, 0x95, 0xE2, 0xBA, 0x52, 
	0x5C, 0x2B, 0xE5, 0x0F, 0xBA, 0x38, 0xF2, 0xDD, 0x24, 0x79, 
	0x91, 0x33, 0xB4, 0x29, 0x5D, 0x8C, 0xB1, 0xA9, 0x5B, 0x5D, 
	0x41, 0xBD, 0xD6, 0xC6, 0xD6, 0x2D, 0xB6, 0x6E, 0x2A, 0xA2, 
	0xC4, 0x62, 0x12, 0xC3, 0xE9, 0xE9, 0x84, 0xFD, 0xC3, 0x57, 
	0x09, 0x31, 0xE0, 0x5A, 0x0E, 0x91, 0xAA, 0x86, 0x35, 0x2A, 
	0xB9, 0xE4, 0x94, 0x65, 0x89, 0xB1, 0x8A, 0x6B, 0x38, 0x62, 
	0x11, 0x08, 0xE6, 0x36, 0x0A, 0x4E, 0xBF, 0xB7, 0x4D, 0x6C, 
	0x6A, 0xB1, 0xA9, 0xC3, 0x65, 0x0E, 0xD7, 0xB0, 0xB8, 0x86, 
	0xC3, 0x35, 0x1C, 0x67, 0xF2, 0xBB, 0x39, 0x17, 0xD7, 0x53, 
	0x6B, 0xD5, 0xAA, 0xD1, 0x55, 0xA3, 0xD6, 0x72, 0x6C, 0x1F, 
	0x50, 0xCA, 0xA2, 0xE4, 0xFC, 0x54, 0xC0, 0x35, 0xDC, 0x7C, 
	0xAC, 0x5D, 0x5D, 0x01, 0x40, 0x57, 0x5F, 0x8B, 0x7C, 0xB2, 
	0xA8, 0xD2, 0x54, 0xB7, 0xD8, 0xCC, 0xD2, 0xDF, 0x9A, 0xE1, 
	0xF1, 0xFB, 0x15, 0x91, 0xEA, 0xD2, 0x2D, 0x58, 0x6F, 0x33, 
	0x30, 0xF4, 0x60, 0x17, 0x63, 0xD7, 0x66, 0x39, 0x39, 0x91, 
	0xE1, 0x1A, 0x0E, 0x31, 0x42, 0xD2, 0xD3, 0x60, 0xE4, 0x8D, 
	0xBE, 0xD5, 0x2F, 0xDA, 0x4F, 0x07, 0x36, 0xC9, 0xE0, 0xFE, 
	0x33, 0x6A, 0x53, 0x87, 0xCD, 0x2C, 0x2E, 0x73, 0x6C, 0x58, 
	0x2F, 0x3C, 0xB3, 0x39, 0x5D, 0xD1, 0xAF, 0x4A, 0x1F, 0xF8, 
	0xE1, 0xE2, 0x0C, 0x47, 0xCF, 0x37, 0xF1, 0xCD, 0x06, 0xCE, 
	0x06, 0xC4, 0x08, 0x77, 0xF5, 0x25, 0x7F, 0xDD, 0x8B, 0x1E, 
	0x3B, 0x72, 0x4E, 0xDB, 0x53, 0xA6, 0x92, 0x9C, 0x59, 0xD2, 
	0x5A, 0x49, 0xB3, 0x56, 0x62, 0x9C, 0xC1, 0x38, 0xA9, 0x54, 
	0xA8, 0x32, 0x17, 0x2C, 0x85, 0x69, 0x12, 0xF2, 0x40, 0xE8, 
	0x04, 0x7C, 0xDB, 0x93, 0x36, 0x3D, 0xDF, 0xEF, 0xEE, 0x93, 
	0x35, 0xBB, 0xE9, 0x13, 0x9F, 0x5D, 0xD2, 0xA2, 0x53, 0xE5, 
	0xDF, 0x35, 0x6B, 0x8B, 0x87, 0x2F, 0x35, 0x83, 0x18, 0x81, 
	0xA8, 0x44, 0xAF, 0x84, 0x22, 0x10, 0xDA, 0x81, 0xD0, 0xF6, 
	0x58, 0x5B, 0x70, 0xE2, 0xB9, 0x5E, 0xF9, 0x47, 0x0F, 0xCE, 
	0xF6, 0xAF, 0xA6, 0xD5, 0x26, 0x06, 0xDB, 0x70, 0xB8, 0xD4, 
	0x61, 0xEA, 0x15, 0x81, 0x46, 0x25, 0x96, 0x91, 0xD0, 0x09, 
	0xC4, 0x3C, 0xF0, 0xED, 0xCE, 0x96, 0xDC, 0xF1, 0x8B, 0x06, 
	0xF0, 0xF4, 0xA9, 0x52, 0xC5, 0x19, 0xC4, 0x49, 0x55, 0xA6, 
	0x54, 0x1D, 0xF4, 0xEB, 0x41, 0x23, 0xFC, 0x6F, 0xFF, 0xD6, 
	0xFE, 0x04, 0xBE, 0xB0, 0xB8, 0x55, 0x9C, 0x23, 0x61, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 
	0x60, 0x82, 
};

wxBitmap& undo_png_to_wx_bitmap()
{
	static wxMemoryInputStream memIStream( undo_png, sizeof( undo_png ) );
	static wxImage image( memIStream, wxBITMAP_TYPE_PNG );
	static wxBitmap bmp( image );
	return bmp;
}


#endif //UNDO_PNG_H
