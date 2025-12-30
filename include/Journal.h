#ifndef JOURNAL_H
#define JOURNAL_H

#include "LibraryItem.h"

/**
 * Journal class derived from LibraryItem
 * Demonstrates: Inheritance for academic publications
 */
class Journal : public LibraryItem {
private:
    int volumeNumber;
    std::string researchField;
    std::string editor;
    bool isPeerReviewed;
    
public:
    // Constructor
    Journal(const std::string& id, const std::string& title, const std::string& publisher,
            int year, int volume, const std::string& field, const std::string& ed, bool peer);
    
    // Override virtual functions
    void displayInfo() const override;
    std::string getItemType() const override;
    double getLateFeePerDay() const override;
    
    // Journal-specific getters
    int getVolumeNumber() const { return volumeNumber; }
    std::string getResearchField() const { return researchField; }
    std::string getEditor() const { return editor; }
    bool getIsPeerReviewed() const { return isPeerReviewed; }
    
    // Serialization
    std::string serialize() const override;
    
    // Destructor
    ~Journal();
};

#endif // JOURNAL_H
