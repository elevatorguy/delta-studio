#ifndef DELTA_BASIC_PATH_H
#define DELTA_BASIC_PATH_H

#include <string>
#include <filesystem>

namespace dbasic {

    class Path {
    protected: Path(const std::filesystem::path &path);
    public:
        Path(const std::wstring &path);
        Path(const wchar_t *path);
        Path(const Path &path);
        Path();
        ~Path();

        std::wstring ToString() const;

        void SetPath(const std::wstring &path);
        bool operator==(const Path &path) const;
        Path Append(const Path &path) const;

        void GetParentPath(Path *path) const;

        const Path &operator=(const Path &b);

        std::wstring GetExtension() const;
        std::wstring GetStem() const;

        Path GetAbsolute() const;

        bool IsAbsolute() const;
        bool Exists() const;

    protected:
        std::filesystem::path *m_path;

    protected:
        const std::filesystem::path &GetBoostPath() const { return *m_path; }
    };

} /* namespace dbasic */

#endif /* DELTA_BASIC_PATH_H */
