#ifndef COPY32X32_PNG_H
#define COPY32X32_PNG_H

#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>

static const unsigned char Copy32x32_png[] =
{
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 
	0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x20, 
	0x00, 0x00, 0x00, 0x20, 0x08, 0x06, 0x00, 0x00, 0x00, 0x73, 
	0x7A, 0x7A, 0xF4, 0x00, 0x00, 0x00, 0x04, 0x73, 0x42, 0x49, 
	0x54, 0x08, 0x08, 0x08, 0x08, 0x7C, 0x08, 0x64, 0x88, 0x00, 
	0x00, 0x02, 0x8A, 0x49, 0x44, 0x41, 0x54, 0x58, 0x85, 0xCD, 
	0x97, 0x4D, 0x6B, 0x13, 0x41, 0x18, 0xC7, 0xFF, 0xCF, 0xCE, 
	0xEE, 0x9A, 0x78, 0x49, 0x0E, 0x96, 0x7E, 0x82, 0x64, 0x8B, 
	0x12, 0xBF, 0x81, 0xE0, 0x41, 0xA4, 0xA7, 0x1C, 0xFC, 0x0E, 
	0x3D, 0xE8, 0x2D, 0x84, 0x46, 0x91, 0x82, 0x27, 0x4B, 0x1B, 
	0xD1, 0x82, 0xF8, 0x82, 0x78, 0xF0, 0xA4, 0x82, 0x57, 0xEF, 
	0x52, 0x2D, 0xC5, 0xA3, 0xA2, 0x1E, 0x02, 0x6A, 0x55, 0x84, 
	0x86, 0xEA, 0x21, 0x49, 0xD9, 0xA4, 0x4B, 0x5E, 0x66, 0x3C, 
	0xC4, 0xDD, 0xEC, 0x2C, 0x3B, 0xFB, 0xA2, 0x1B, 0xF4, 0x81, 
	0x90, 0x99, 0x9D, 0xD9, 0xF9, 0xFF, 0xE6, 0xFF, 0x3C, 0xB3, 
	0xD9, 0x00, 0xFF, 0x38, 0x08, 0x00, 0xB6, 0xB6, 0x9A, 0x17, 
	0x9D, 0xE1, 0x68, 0x31, 0xCB, 0x85, 0x4D, 0xD3, 0xF8, 0x59, 
	0xAF, 0x35, 0xEE, 0xC6, 0xCD, 0xD3, 0x01, 0xC0, 0x19, 0x8E, 
	0x16, 0xAF, 0x34, 0xAE, 0x66, 0xA9, 0x8F, 0x8D, 0xE6, 0xFA, 
	0x42, 0x92, 0x79, 0xBA, 0xBF, 0xD3, 0xED, 0x76, 0x33, 0x11, 
	0x2F, 0x16, 0x8B, 0x89, 0xE7, 0x6A, 0x99, 0x28, 0xFE, 0x45, 
	0xE8, 0xF1, 0x53, 0x92, 0x07, 0xE7, 0x7C, 0x3E, 0x00, 0x4F, 
	0x9F, 0x3D, 0xBE, 0x74, 0xD8, 0xEB, 0x25, 0xCA, 0xA9, 0x1B, 
	0x44, 0xC0, 0x46, 0xF3, 0xFA, 0x35, 0xD5, 0xB8, 0x61, 0x18, 
	0xEF, 0xEB, 0xB5, 0xC6, 0xE9, 0x50, 0x80, 0x56, 0xAB, 0x25, 
	0xF5, 0x0F, 0x7B, 0xBD, 0x85, 0xCB, 0xAB, 0xD9, 0x16, 0xE9, 
	0xE6, 0x8D, 0xF5, 0x0A, 0xA0, 0x70, 0x60, 0x69, 0x69, 0x49, 
	0xEA, 0xBF, 0xDC, 0x79, 0x01, 0x20, 0x9B, 0x22, 0x25, 0x22, 
	0x14, 0x0A, 0x05, 0xAF, 0xFF, 0x7F, 0x16, 0x61, 0x30, 0x05, 
	0x59, 0x85, 0x10, 0x22, 0x19, 0x80, 0x2A, 0x05, 0x59, 0x08, 
	0x07, 0x21, 0x22, 0x4F, 0x81, 0xEA, 0x58, 0xA5, 0x71, 0xC8, 
	0x15, 0x14, 0x42, 0xA0, 0x54, 0x2A, 0x41, 0xD7, 0x65, 0x49, 
	0x65, 0x0A, 0xA2, 0xCE, 0x74, 0xD0, 0xA1, 0x28, 0xE1, 0x20, 
	0x44, 0xAC, 0x03, 0x9C, 0x73, 0x94, 0xCB, 0x65, 0xE9, 0xDA, 
	0xCE, 0xEE, 0x76, 0xAC, 0x60, 0x9C, 0x70, 0xD8, 0x78, 0x28, 
	0x40, 0x10, 0x26, 0x2C, 0x54, 0x29, 0x88, 0x12, 0xB4, 0x2C, 
	0x2B, 0xF4, 0x1E, 0x09, 0xC0, 0x15, 0x4C, 0x9B, 0x82, 0xA8, 
	0x5D, 0x07, 0xC7, 0x88, 0x48, 0x0D, 0xE0, 0x42, 0x04, 0x53, 
	0xB0, 0xFB, 0xFA, 0x55, 0x28, 0x48, 0x52, 0xBB, 0xE7, 0x92, 
	0x82, 0xA4, 0x82, 0xC0, 0xD4, 0x7E, 0x15, 0x84, 0x07, 0xC0, 
	0x39, 0xF7, 0x04, 0xA3, 0xEC, 0x17, 0x42, 0x78, 0xF9, 0x8C, 
	0xB3, 0xDB, 0xFD, 0xF6, 0xB7, 0x89, 0x48, 0x5A, 0x5F, 0x02, 
	0x48, 0x22, 0x9E, 0x44, 0x30, 0x6E, 0x7E, 0x24, 0x80, 0x3F, 
	0x82, 0xD7, 0xDC, 0x05, 0x54, 0x29, 0x88, 0x83, 0xB1, 0x2C, 
	0x0B, 0x44, 0x94, 0x4D, 0x0A, 0xFE, 0xA4, 0x00, 0x19, 0x63, 
	0xEA, 0x27, 0x61, 0xD6, 0x29, 0xF0, 0x8F, 0x69, 0x9A, 0x06, 
	0xC6, 0x98, 0x07, 0xA0, 0x69, 0xB3, 0x1F, 0x61, 0x09, 0x20, 
	0x97, 0xCB, 0x49, 0x10, 0xFE, 0x89, 0xC1, 0x62, 0x4A, 0xB2, 
	0x7B, 0x22, 0x92, 0x84, 0xDD, 0xF6, 0x7E, 0x7B, 0x1F, 0x02, 
	0x62, 0x06, 0x60, 0x9A, 0xC6, 0xC1, 0x9D, 0x7B, 0xB7, 0x95, 
	0xFF, 0x0B, 0x88, 0x66, 0x50, 0x69, 0xEC, 0x26, 0x22, 0x3C, 
	0x7C, 0xF4, 0x00, 0xA6, 0x69, 0x02, 0x00, 0x4C, 0xC3, 0xC4, 
	0x70, 0x34, 0x44, 0x3E, 0x97, 0x9F, 0x2E, 0xEA, 0x02, 0xD4, 
	0x6B, 0x8D, 0xFB, 0x2A, 0x71, 0x60, 0xFA, 0x6E, 0xC7, 0x39, 
	0x57, 0xDA, 0x1C, 0x65, 0x37, 0x00, 0x9C, 0x3B, 0x7B, 0x1E, 
	0xEE, 0xFD, 0x8E, 0xE3, 0xE0, 0xED, 0xBB, 0x37, 0x20, 0xD0, 
	0x13, 0x0F, 0x20, 0x49, 0x84, 0x01, 0xF8, 0xDB, 0x2A, 0xBB, 
	0x19, 0x63, 0xE0, 0x9C, 0xA3, 0xD3, 0xE9, 0x40, 0x08, 0x81, 
	0x4F, 0x7B, 0x1F, 0x61, 0x1F, 0xD9, 0x3D, 0xA7, 0x3F, 0x5C, 
	0x49, 0x0D, 0xA0, 0xDA, 0xB5, 0x4A, 0x58, 0xD7, 0x75, 0x70, 
	0xCE, 0x31, 0x18, 0x0C, 0x60, 0xDB, 0x36, 0xBE, 0x7D, 0xFF, 
	0x8A, 0xC1, 0x91, 0xDD, 0x39, 0x59, 0xA9, 0x9C, 0xA9, 0x2E, 
	0x57, 0x07, 0xA9, 0x00, 0x26, 0x93, 0x09, 0xF2, 0xF9, 0xBC, 
	0x54, 0x8C, 0x44, 0x04, 0x22, 0x82, 0xA6, 0x69, 0xD2, 0x87, 
	0x31, 0x06, 0x21, 0x04, 0xFA, 0x7D, 0x1B, 0x00, 0xB0, 0xF7, 
	0xE5, 0x33, 0xDA, 0x3F, 0xDA, 0x02, 0x02, 0xDB, 0xC7, 0x4E, 
	0x1C, 0xBF, 0x50, 0x5D, 0xAE, 0x7A, 0x6F, 0xB7, 0x14, 0x2E, 
	0x27, 0xC7, 0xCD, 0x5B, 0x9B, 0x1F, 0x46, 0xE3, 0xF1, 0xA9, 
	0xA4, 0xB0, 0x6E, 0x88, 0xDF, 0xB5, 0xAE, 0x31, 0x76, 0x30, 
	0xE6, 0x93, 0x95, 0xB5, 0xD5, 0xB5, 0xE7, 0x69, 0xD7, 0x98, 
	0x7B, 0xFC, 0x02, 0x56, 0x54, 0x0C, 0xEF, 0x1E, 0x4D, 0xF4, 
	0xBB, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 
	0x42, 0x60, 0x82, 
};

wxBitmap& Copy32x32_png_to_wx_bitmap()
{
	static wxMemoryInputStream memIStream( Copy32x32_png, sizeof( Copy32x32_png ) );
	static wxImage image( memIStream, wxBITMAP_TYPE_PNG );
	static wxBitmap bmp( image );
	return bmp;
}


#endif //COPY32X32_PNG_H
